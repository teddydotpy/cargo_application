#include "../headers/containers.h"
#include "../headers/box_view.h"
#include "../headers/cylinder_view.h"
#include "../headers/unallocated_view.h"
#include "../headers/unallocated_list.h"
#include "../headers/allocated_packages.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

ContainerWidget::~ContainerWidget(){
}

void ContainerWidget::setupViews(){
    main_layout = new QVBoxLayout(this);
    top_layout = new QHBoxLayout();
    code_list = new UncallocatedView(this);

    top_layout->addWidget(box);
    top_layout->addSpacing(10);
    top_layout->addWidget(cylinder);

    main_layout->addItem(top_layout);
    main_layout->addWidget(code_list);
    this->setLayout(main_layout);

    emit sendAllocatedMap(allocateMap);
}

void ContainerWidget::newPackage(int diameter, int height, int weight){
    QString item = pkg_list->newPackage(diameter, height, weight);
    emit newContainer(item);
    emit updateStatus("New Cylinder added to unallocated items list:  " + item);
}   

void ContainerWidget::newPackage(int length, int breadth, int height, int weight){
    QString item = pkg_list->newPackage(length, breadth, height, weight);
    emit newContainer(item);
    emit updateStatus("New Box added to unallocated items list:  " + item);
}

void ContainerWidget::paletteUpdate(int paletter, int pos){
    if (pkg_list->count() >= 1){
        pkg_list->at(pos)->setPallete(paletter);
        allocateMap->add_new(pkg_list->at(pos), paletter);
        pkg_list->removeAt(pos);
    }
    emit sendAllocatedMap(allocateMap);
}

void ContainerWidget::reallocate(Package *obj){
    pkg_list->append(obj);
    emit newContainer(obj->getCode());
    emit updateStatus(obj->getCode() + " has ben de-allocated and returned to unallocated list." );
}