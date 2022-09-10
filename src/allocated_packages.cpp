#include "../headers/allocated_packages.h"

#include <QMap>

AllocatedMap::AllocatedMap(){
    // It is quite sad and lonely here...
}
 
AllocatedMap::~AllocatedMap(){
    // Hey wassup up there you good ??
    for(auto palette: this->keys()){
        delete this->value(palette);
    }
}

void AllocatedMap::add_new(Package *container, int palette_id){
    if(this->contains(palette_id)){
        this->value(palette_id)->append(container);
    } else {
        this->insert(palette_id, new QList<Package*>());
        this->value(palette_id)->append(container);
    }

}

void AllocatedMap::deallocate(QString code){
    for(auto palette: this->keys()){
        for(int i = 0; i < this->value(palette)->length(); i++){
            if(this->value(palette)->at(i)->getCode() == code){
                this->value(palette)->removeAt(i);
            }
        }
    }
}

Package *AllocatedMap::getPackage(QString code){
    Package *item = nullptr;
    for(auto palette: this->keys()){
        for(int i = 0; i < this->value(palette)->length(); i++){
            if(this->value(palette)->at(i)->getCode() == code){
                item = this->value(palette)->at(i);
            }
        }
    }

    return item;
}