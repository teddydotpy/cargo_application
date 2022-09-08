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
