#ifndef CYLINDER_H
#define CYLINDER_H

#include "package.h"
#include <QChar>

class Cylinder : public Package{
    public:
        Cylinder();
        Cylinder(Cylinder &other);
        Cylinder(int diameter, int height, int weight, int Id);
        ~Cylinder();

        int getDiameter();
        int getHeight();
        int setDiameter(int Diameter);
        int setHeight(int height);
        QChar getContainerType();
        float getVolume();

    private:
        int diameter, height;
        QChar container_type;
};

#endif