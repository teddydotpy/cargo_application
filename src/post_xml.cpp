#include "../headers/post_xml.h"
#include "../headers/allocated_packages.h"

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
}

void PostXmlWidget::setupView(){

    packages = nullptr;
     
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
}

void PostXmlWidget::updateXml(QString xmldata){
    xml_view->setText(xmldata);
    xml_view->update();
}

void PostXmlWidget::handleDeallocation(){

}

void PostXmlWidget::sendXMl(){

}

void PostXmlWidget::SerializeXml(){

    if (packages != nullptr){
        for(auto palette: packages->keys()){
            int palette_volume = 0, palette_weight = 0;

            for(auto container: *packages->value(palette)){
                palette_weight += container->getWeight();
                palette_volume += container->getVolume();
            }
        }
    }
}

void PostXmlWidget::recieveAllocatedPackages(AllocatedMap *map){
    if (packages == nullptr){
        packages = map;
    } 
}