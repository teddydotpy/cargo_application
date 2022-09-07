#include "../headers/box.h"
#include <QChar>

Box::Box(){
    length = 0.0f;
    breadth = 0.0f;
    height = 0.0f;
    container_type = 'B';
}

Box::Box(Box &other){
    length = other.length;
    breadth = other.breadth;
    height = other.breadth;
    container_type = 'B';
}

Box::Box(float length, float breadth, float height, float weight, int Id)
    :Package(Id, weight){
    length = length;
    breadth = breadth;
    height = breadth;
    container_type = 'B';
}

Box::~Box(){
    //Nothing here either.
}


const float Box::getLength(){
    return length;
}

const float Box::getBreadth(){
    return breadth;
}

const float Box::getHeight(){
    return height;
}

float Box::setLength(float lengthobj){
    length = lengthobj;
}

float Box::setBreadth(float breadthobj){
    breadth = breadthobj;
}

float Box::setHeight(float heightobj){
    height = heightobj;
}

const QChar Box::getConainerType(){
    return container_type;
}
