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

Cylinder::Cylinder(int diameter_val, int height_val, int weight, int Id)
    :Package(Id, weight){
    diameter = diameter_val;
    height = height_val;
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

void Cylinder::setDiameter(int Diameter){
    diameter = Diameter;
}

void Cylinder::setHeight(int heightob){
    height = heightob;
}

QChar Cylinder::getContainerType(){
    return container_type;
}

float Cylinder::getVolume(){

    return M_PI*pow(getDimensions()->at(0)/2, 2)*getDimensions()->at(1);
}
