#ifndef CYLINDER_H
#define CYLINDER_H

#include "package.h"
#include <QChar>

class Cylinder : public Package{
    public:
        Cylinder();
        Cylinder(Cylinder &other);
        Cylinder(float diameter, float height, float weight, int Id);
        ~Cylinder();

        float getDiameter();
        float getHeight();
        float setDiameter(float Diameter);
        float setHeight(float height);
        QChar getContainerType();
        float getVolume();

    private:
        float diameter, height;
        QChar container_type;
};

#endif