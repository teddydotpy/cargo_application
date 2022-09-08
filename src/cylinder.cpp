#include "../headers/cylinder.h"

#include <QChar>
#include <math.h>

Cylinder::Cylinder(){
    diameter = 0;
    height = 0;
    container_type = 'C';
}

Cylinder::Cylinder(Cylinder &other){
    diameter = other.diameter;
    height = other.height;
    container_type = 'C';
}

Cylinder::Cylinder(int diameter, int height, int weight, int Id)
    :Package(Id, weight){
    diameter = diameter;
    height = height;
    container_type = 'C';
    this->setDimensions(diameter, height);
    this->setVolume(this->getVolume());
}

Cylinder::~Cylinder(){
    //Not much to destroy yet :D
}

int Cylinder::getDiameter(){
    return diameter;
}

int Cylinder::getHeight(){
    return height;
}

int Cylinder::setDiameter(int Diameter){
    diameter = Diameter;
}

int Cylinder::setHeight(int heightob){
    height = heightob;
}

QChar Cylinder::getContainerType(){
    return container_type;
}

float Cylinder::getVolume(){

    return M_PI*pow(getDimensions()->at(0)/2, 2)*getDimensions()->at(1);
}
