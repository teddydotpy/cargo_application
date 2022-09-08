#ifndef BOX_H
#define BOX_H

#include "package.h"
#include <QChar>

class Box : public Package{
    public:
        Box();
        Box(Box &other);
        Box(int length, int breadth, int height, int weight, int Id);
        ~Box();

        const int getLength();
        const int getBreadth();
        const int getHeight();
        int setLength(int length);
        int setBreadth(int breadth);
        int setHeight(int height);
        const QChar getConainerType();
        float getVolume();


    private:
        int length, breadth, height;
        QChar container_type;
};

#endif