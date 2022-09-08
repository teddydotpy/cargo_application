#include <QList>
#include <QString>

#include "../headers/unallocated_list.h"
#include "../headers/cylinder.h"
#include "../headers/box.h"

UnallocatedList::UnallocatedList()
    :QList(){
        current_id = 0;
}

UnallocatedList::~UnallocatedList(){
    delete container_c;
    delete container_b;
}

void UnallocatedList::appendList(Package *pkg){
    this->append(pkg);
}

QString UnallocatedList::newPackage(int diameter, int height, int weight){
    current_id += 1;
    container_c = new Cylinder(diameter, height, weight, current_id);
    container_c->generatePackageCode(container_c->getContainerType());
    qDebug() << "H: " << container_b->getHeight() << "\nD: " << container_c->getDiameter();
    container_c->setVolume(container_c->getVolume());
    appendList(container_c);
    return container_c->getCode();
}

QString UnallocatedList::newPackage(int length, int breadth, int height, int weight){
    current_id += 1;
    container_b = new Box(length, breadth, height, weight, current_id);
    container_b->generatePackageCode(container_b->getConainerType());
    qDebug() << "H: " << container_b->getHeight() << "\nB: " << container_b->getBreadth() << "\nL: " << container_b->getLength();
    container_b->setVolume(container_b->getVolume());
    appendList(container_b);
    return container_b->getCode();
}


