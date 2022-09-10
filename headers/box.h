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

        int getLength();
        int getBreadth();
        int getHeight();
        void setLength(int length);
        void setBreadth(int breadth);
        void setHeight(int height);
        const QChar getConainerType();
        float getVolume();


    private:
        int length, breadth, height;
        QChar container_type;
};

#endif