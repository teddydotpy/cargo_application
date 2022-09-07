#ifndef UNALLOCATED_LIST_H
#define UNALLOCATED_LIST_H

#include <QList>
#include "package.h"

class Cylinder;
class Box;
class QString;
class UnallocatedList : public QList<Package*>{
    public:
        UnallocatedList();
        UnallocatedList(UnallocatedList &other);
        UnallocatedList(QList<Package*> *pList);
        ~UnallocatedList();
        void appendList(Package *container);
        QString newPackage(float diameter, float height, float weight);
        QString newPackage(float length, float breadth, float height, float weight);

    private:
        int current_id;
        Box *container_b;
        Cylinder *container_c;

};

#endif 