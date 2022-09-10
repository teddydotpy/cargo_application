#ifndef ALLOCATED_MAP_H
#define ALLOCATED_MAP_H

#include <QMap>
#include <QList>
#include "package.h"

class AllocatedMap : public QMap<int, QList<Package*>*>{
    public:
        AllocatedMap();
        ~AllocatedMap();
        void add_new(Package *container, int palette_id);
        void deallocate(QString code);
        Package *getPackage(QString code);

    signals:
        void newValue(Package *item);

};

#endif 