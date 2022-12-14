#include "../headers/post_xml.h"
#include "../headers/allocated_packages.h"
#include "../headers/network_client.h"

#include <QXmlStreamWriter>
#include <QtConcurrent>
#include <QFuture>
#include <QMutex>
#include <QMutexLocker>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QString>
#include <QList>
#include <QLabel>

PostXmlWidget::~PostXmlWidget(){
    delete top_layout;
    delete bottom_layout;
    delete xml_output;
    sendSocket->~NetworkClient();
}

void PostXmlWidget::setupView(){

    packages = nullptr;
    mute_x = new QMutex();
    sendSocket = new NetworkClient();
    sendSocket->connect();
    xml_output = new QString();
    to_be_posted = new QString();
     
    main_layout = new QVBoxLayout(this);
    top_layout = new QVBoxLayout();
    bottom_layout = new QVBoxLayout();

    button_layout = new QHBoxLayout();
    server_buttons = new QHBoxLayout();
 
    post_b = new QPushButton("Post to Server", this);
    connect_button = new QPushButton("Connect To Server", this);
    deallocate = new QPushButton("Deallocate", this);
    serialize = new QPushButton("Serialize Palletes", this);
 
    xml_view = new QTextEdit("You have no objects allocated to palettes yet.", this);
    xml_view->setReadOnly(true);
 
    allocated_view = new QListWidget(this);
 
    top_label = new QLabel("XML Viewer", this, Qt::WindowFlags());
    bottom_label = new QLabel("Deallocation Center", this, Qt::WindowFlags());

    server_buttons->addWidget(post_b);
    server_buttons->addWidget(connect_button);
    
    button_layout->addWidget(serialize);
    button_layout->addLayout(server_buttons);
    
    top_layout->addWidget(top_label);
    top_layout->addWidget(xml_view);
    top_layout->addLayout(button_layout);

    top_layout->addWidget(bottom_label);
    top_layout->addWidget(allocated_view);
    top_layout->addWidget(deallocate);

    main_layout->addLayout(top_layout);
    main_layout->addLayout(bottom_layout);

    connect(post_b, SIGNAL(clicked()), this, SLOT(sendXMl()));
    connect(serialize, SIGNAL(clicked()), this, SLOT(threadedSerialization()));
    connect(deallocate, SIGNAL(clicked()), this, SLOT(handleDeallocation()));
    connect(connect_button, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(this, SIGNAL(updateXmlViewer()), this, SLOT(updateXml()));
}

void PostXmlWidget::updateXml(){
    QMutexLocker lock(mute_x);
    *to_be_posted = *xml_output;
    xml_view->clear();
    xml_view->setText(*xml_output);
    xml_view->update();
    delete xml_output;
    xml_output = new QString();
}

void PostXmlWidget::handleDeallocation(){
    if(allocated_view->count() > 0 && allocated_view->selectedItems().count() > 0){
        QList<QListWidgetItem*> selected = allocated_view->selectedItems();
        Package *deallocatedItem = packages->getPackage(selected[0]->text());
        if(deallocatedItem != nullptr){
            emit deallocatePackage(deallocatedItem);
        }

        packages->deallocate(selected[0]->text());
        qDeleteAll(selected);
    } else {
        handleEmptyList();
    }
    
}

void PostXmlWidget::sendXMl(){
    if(to_be_posted->isEmpty()){
        handleNoData();
    }else{
        if(sendSocket->isValid()){
            sendSocket->writeToServer(*to_be_posted);
            emit updateStatus("Sent to server...");
        } else {
            emit updateStatus("The server is down please contact support.");
        }
    }
    
}

void PostXmlWidget::SerializeXml(){
    QXmlStreamWriter *strema = new QXmlStreamWriter(xml_output);
    strema->setAutoFormatting(true);
    strema->writeStartDocument();
    strema->writeStartElement("Pallets");
    if (packages != nullptr){
        QString noPallets = QString::number(packages->count());
        strema->writeAttribute("NumberOfPallets", noPallets);
        for(auto palette: packages->keys()){
            int palette_volume = 0, palette_weight = 0;
            strema->writeStartElement("Pallete");

            for(auto container: *packages->value(palette)){
                palette_weight += container->getWeight();
                palette_volume += container->getVolume();
            }

            strema->writeAttribute("weight", QString::number(palette_weight));
            strema->writeAttribute("volume", QString::number(palette_volume));
            strema->writeAttribute("number", QString::number(palette));

            for(auto container: *packages->value(palette)){
                if (container->getDimensions()->length() == 2){
                    strema->writeStartElement("Cylinder");
                        strema->writeTextElement("code", container->getCode());
                        strema->writeTextElement("weight", QString::number(container->getWeight()));
                        strema->writeTextElement("height", QString::number(container->getDimensions()->at(1)));
                        strema->writeTextElement("diameter", QString::number(container->getDimensions()->at(0)));
                    strema->writeEndElement();
                } else {
                    strema->writeStartElement("Box");
                        strema->writeTextElement("code", container->getCode());
                        strema->writeTextElement("weight", QString::number(container->getWeight()));
                        strema->writeTextElement("height", QString::number(container->getDimensions()->at(2)));
                        strema->writeTextElement("length", QString::number(container->getDimensions()->at(0)));
                        strema->writeTextElement("breadth", QString::number(container->getDimensions()->at(1)));
                    strema->writeEndElement();
                }
                
            } 
            strema->writeEndElement();
        }
    } else {
        strema->writeAttribute("NumberOfPallets", 0);
    }
    strema->writeEndElement();
    strema->writeEndDocument();
    emit updateXmlViewer();
}

void PostXmlWidget::recieveAllocatedPackages(AllocatedMap *map){
    if (packages == nullptr){
        packages = map;
    } 

    this->handleNewAllocated();
}

void PostXmlWidget::handleNoData(){
    QMessageBox::warning(this, "Cargo App",
        tr("You have no data to send please do better.\n"),
        QMessageBox::Ok,
        QMessageBox::Ok);
}

void PostXmlWidget::handleEmptyList(){
    QMessageBox::warning(this, "Cargo App",
        tr("Cannot deallocate nothing now can we.\n"),
        QMessageBox::Ok,
        QMessageBox::Ok);

}

void PostXmlWidget::handleNewAllocated(){
    allocated_view->clear();
    for(auto palette: packages->keys()){
        for(auto container: *packages->value(palette)){
            allocated_view->addItem(container->getCode());
        }
    }
}

void PostXmlWidget::connectToServer(){
    sendSocket->connect();
}

void PostXmlWidget::threadedSerialization(){
    QFuture<void> future = QtConcurrent::run(&PostXmlWidget::SerializeXml, this);
}