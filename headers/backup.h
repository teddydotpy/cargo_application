#ifndef BACKUP_H
#define BACKUP_H

#include <QJsonDocument>
#include <QList>
#include <QMap>

#include "package.h"

class QFile;
class Backup: public QJsonDocument{
    public:
        Backup(QList<Package*> &list, QMap<Package*, int> &map);
        ~Backup();
        void setRecentId(int id);
        int getRecentId();
        QJsonDocument unallocateFileBackup();
        QJsonDocument  allocateFileBackup();
        QList<Package*> unallocateFileRestore(QFile jsonFile);
        QMap<Package*, int>  allocateFileRestore(QFile jsonFile);
        QList<Package*> *unallocateMemoryRestore();
        QMap<Package*, int>  *allocateMemoryRestore();

    private:
        int recent_id;
        QList<Package*> *unallocated_packages;
        QMap<Package*, int> *allocated_packages;

};

#endif