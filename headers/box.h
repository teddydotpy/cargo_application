#ifndef BOX_H
#define BOX_H

#include "package.h"
#include <QChar>

class Box : public Package{
    public:
        Box();
        Box(Box &other);
        Box(float length, float breadth, float height, float weight, int Id);
        ~Box();

        const float getLength();
        const float getBreadth();
        const float getHeight();
        float setLength(float length);
        float setBreadth(float breadth);
        float setHeight(float height);
        const QChar getConainerType();
        float getVolume();


    private:
        float length, breadth, height;
        QChar container_type;
};

#endif