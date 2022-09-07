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

QString UnallocatedList::newPackage(float diameter, float height, float weight){
    current_id += 1;
    container_c = new Cylinder(diameter, height, weight, current_id);
    container_c->generatePackageCode(container_c->getContainerType());
    appendList(container_c);
    return container_c->getCode();
}

QString UnallocatedList::newPackage(float length, float breadth, float height, float weight){
    current_id += 1;
    container_b = new Box(length, breadth, height, weight, current_id);
    container_b->generatePackageCode(container_b->getConainerType());
    appendList(container_b);
    return container_b->getCode();
}


