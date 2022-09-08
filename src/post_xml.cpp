#include "../headers/post_xml.h"
#include "../headers/allocated_packages.h"

#include <QXmlStreamWriter>
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
}

void PostXmlWidget::setupView(){

    packages = nullptr;
    xml_output = new QString();
     
    main_layout = new QVBoxLayout(this);
    top_layout = new QVBoxLayout();
    bottom_layout = new QVBoxLayout();

    button_layout = new QHBoxLayout();
 
    post_b = new QPushButton("Post to Server", this);
    deallocate = new QPushButton("Deallocate", this);
    serialize = new QPushButton("Serialize Palletes", this);
 
    xml_view = new QTextEdit("You have no objects allocated to palettes yet.", this);
    xml_view->setReadOnly(true);
 
    allocated_view = new QListWidget(this);
 
    top_label = new QLabel("XML Viewer", this, Qt::WindowFlags());
    bottom_label = new QLabel("Deallocation Center", this, Qt::WindowFlags());

    button_layout->addWidget(serialize);
    button_layout->addWidget(post_b);

    top_layout->addWidget(top_label);
    top_layout->addWidget(xml_view);
    top_layout->addLayout(button_layout);

    top_layout->addWidget(bottom_label);
    top_layout->addWidget(allocated_view);
    top_layout->addWidget(deallocate);

    main_layout->addLayout(top_layout);
    main_layout->addLayout(bottom_layout);

    connect(post_b, SIGNAL(clicked()), this, SLOT(sendXMl()));
    connect(serialize, SIGNAL(clicked()), this, SLOT(SerializeXml()));
    connect(deallocate, SIGNAL(clicked()), this, SLOT(handleDeallocation()));
    connect(this, SIGNAL(updateXmlViewer()), this, SLOT(updateXml()));
}

void PostXmlWidget::updateXml(){
    xml_view->clear();
    xml_view->setText(*xml_output);
    xml_view->update();
    delete xml_output;
    xml_output = new QString();
}

void PostXmlWidget::handleDeallocation(){

}

void PostXmlWidget::sendXMl(){

}

void PostXmlWidget::SerializeXml(){
    QString noPallets = QString::number(packages->count());
    QXmlStreamWriter *strema = new QXmlStreamWriter(xml_output);
    strema->setAutoFormatting(true);
    strema->writeStartDocument();
    strema->writeStartElement("Pallets");
    strema->writeAttribute("NumberOfPallets", noPallets);
    if (packages != nullptr){
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
    }
    strema->writeEndElement();
    strema->writeEndDocument();
    emit updateXmlViewer();
}

void PostXmlWidget::recieveAllocatedPackages(AllocatedMap *map){
    if (packages == nullptr){
        packages = map;
    } 
}