#include "../headers/box.h"
#include <QChar>

Box::Box(){
    length = 0;
    breadth = 0;
    height = 0;
    container_type = 'B';
}

Box::Box(Box &other){
    length = other.length;
    breadth = other.breadth;
    height = other.height;
    container_type = 'B';
}

Box::Box(int length_val, int breadth_val, int height_val, int weight, int Id)
    :Package(Id, weight){
    length = length_val;
    breadth = breadth_val;
    height = height_val;
    container_type = 'B';
    this->setDimensions(length, breadth, height);
    this->setVolume(this->getVolume());
}

Box::~Box(){
    //Nothing here either.
}


int Box::getLength(){
    return length;
}

int Box::getBreadth(){
    return breadth;
}

int Box::getHeight(){
    return height;
}

void Box::setLength(int lengthobj){
    length = lengthobj;
}

void Box::setBreadth(int breadthobj){
    breadth = breadthobj;
}

void Box::setHeight(int heightobj){
    height = heightobj;
}

const QChar Box::getConainerType(){
    return container_type;
}

float Box::getVolume(){
    return getDimensions()->at(0) * getDimensions()->at(1) * getDimensions()->at(2);
}