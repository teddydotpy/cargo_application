#include "../headers/backup.h"
#include "../headers/package.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QChar>
#include <QString>
#include <QFile>
#include <QVariantList>
#include <QList>
#include <QListIterator>
#include <QMap>


Backup::Backup(QList<Package*> &list, QMap<Package*, int> &map){
    recent_id = 0;
    unallocated_packages = new QList<Package*>(list);
    allocated_packages = new QMap<Package*, int>(map);
}

Backup::~Backup(){
    delete unallocated_packages;
    delete allocated_packages;
}

void Backup::setRecentId(int id){
    recent_id = id;
}

int Backup::getRecentId(){
    return recent_id;
}


QJsonDocument Backup::unallocateFileBackup(){
    QJsonArray entireDoc;
    QJsonObject fileBackup;
    // for (auto package: unallocated_packages){
    //     fileBackup.insert("Id", package->getId());
    //     fileBackup.insert("container_type", package->getConainerType());
    //     fileBackup.insert("package_code", package->getCode());
    //     fileBackup.insert("weight", package->getWeight());
    //     fileBackup.insert("height", package->getHeight());

    //     if (package->getConainerType().toLower() == 'c'){
    //         fileBackup.insert("diameter", package->getDiameter());
    //     } else {
    //         fileBackup.insert("length", package->getLength());
    //         fileBackup.insert("breadth", package->getBreadth());
    //     }

    //     entireDoc.append(fileBackup);
    // }

    QJsonDocument doc = QJsonDocument(entireDoc);
    QFile jsonFile("./config/unallocated_items_backup.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

    return doc;
}

QJsonDocument Backup::allocateFileBackup(){
    QJsonArray entireDoc;
    QJsonObject fileBackup;
    // This seems like too much work to figure out for extra marks but I will be thinking about it. 
    // foreach(auto package, allocated_packages->keys()){
    //     fileBackup.insert("Id", package->getId());
    //     fileBackup.insert("container_type", package->getConainerType());
    //     fileBackup.insert("package_code", package->getCode());
    //     fileBackup.insert("palette", allocated_packages->value(package));
    //     fileBackup.insert("weight", package->getWeight());
    //     fileBackup.insert("height", package->getHeight());

    //     if (package->getConainerType().toLower() == 'c'){
    //         fileBackup.insert("diameter", package->getDiameter());
    //     } else {
    //         fileBackup.insert("length", package->getLength());
    //         fileBackup.insert("breadth", package->getBreadth());
    //     }

    //     entireDoc.append(fileBackup);
    // }

    QJsonDocument doc = QJsonDocument(entireDoc);
    QFile jsonFile("./config/allocated_items_backup.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

    return doc;
}

QList<Package*> Backup::unallocateFileRestore(QFile jsonFile){
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument().fromJson(jsonFile.readAll());

    QList<Package*> play;
    return play;
}

QMap<Package*, int>  Backup::allocateFileRestore(QFile jsonFile){
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument doc = QJsonDocument().fromJson(jsonFile.readAll());

    QMap<Package*, int> pla2;
    return pla2;
}

QList<Package*> *Backup::unallocateMemoryRestore(){
    return unallocated_packages;
}

QMap<Package*, int> *Backup::allocateMemoryRestore(){
    return allocated_packages;
}

