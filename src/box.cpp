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

Box::Box(int length, int breadth, int height, int weight, int Id)
    :Package(Id, weight){
    length = length;
    breadth = breadth;
    height = height;
    container_type = 'B';
    this->setDimensions(length, breadth, height);
    this->setVolume(this->getVolume());
}

Box::~Box(){
    //Nothing here either.
}


const int Box::getLength(){
    return length;
}

const int Box::getBreadth(){
    return breadth;
}

const int Box::getHeight(){
    return height;
}

int Box::setLength(int lengthobj){
    length = lengthobj;
}

int Box::setBreadth(int breadthobj){
    breadth = breadthobj;
}

int Box::setHeight(int heightobj){
    height = heightobj;
}

const QChar Box::getConainerType(){
    return container_type;
}

float Box::getVolume(){
    return length*breadth*height;
}