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
        QString newPackage(int diameter, int height, int weight);
        QString newPackage(int length, int breadth, int height, int weight);

    private:
        int current_id;
        Box *container_b;
        Cylinder *container_c;

};

#endif 