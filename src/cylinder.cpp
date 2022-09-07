#include "../headers/cylinder.h"

#include <QChar>


Cylinder::Cylinder(){
    diameter = 0.0f;
    height = 0.0f;
    container_type = 'C';
}

Cylinder::Cylinder(Cylinder &other){
    diameter = other.diameter;
    height = other.height;
    container_type = 'C';
}

Cylinder::Cylinder(float diameter, float height, float weight, int Id)
    :Package(Id, weight){
    diameter = diameter;
    height = height;
    container_type = 'C';
}

Cylinder::~Cylinder(){
    //Not much to destroy yet :D
}

float Cylinder::getDiameter(){
    return diameter;
}

float Cylinder::getHeight(){
    return height;
}

float Cylinder::setDiameter(float Diameter){
    diameter = Diameter;
}

float Cylinder::setHeight(float heightob){
    height = heightob;
}

QChar Cylinder::getContainerType(){
    return container_type;
}

