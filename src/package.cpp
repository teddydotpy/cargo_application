#include "../headers/package.h"

#include <QString>
#include <QChar>
#include <QDateTime>

Package::Package(){
    package_code = "";
    pallete = 0;
    weight = 0;
}

Package::Package(const Package &other){
    Id = other.Id + 1;
    pallete = other.pallete;
    weight = other.weight;
    package_code = "";
}

Package::Package(int Id_b, int weight_b){
    Id = Id_b;
    weight = weight_b;
    package_code = "";
    pallete = 0;
    weight = 0;
}

Package::~Package(){

}

QString Package::getCode(){
    return package_code;
}


int Package::getPallete(){
    return pallete;
}

int Package::getId(){
    return Id;
}


int Package::getWeight(){
    return weight;
}

void Package::setCode(QString code){
    package_code = code;
}

void Package::setPallete(int other_palette){
    pallete = other_palette;
}

void Package::setWeight(int other_weight){
    weight = other_weight;
}

void Package::generatePackageCode(QChar packageType){
    QDateTime *today = new QDateTime();
    QString year = QString::number(today->currentDateTime().date().year());
    QString month = QString::number(today->currentDateTime().date().month());
    QString code_str;
    if(packageType.toLower() == 'c'){
        code_str = QString("%1/%2/%3").arg(year, month, "C" + QString::number(Id));
    } else if(packageType.toLower() == 'b'){
        code_str = QString("%1/%2/%3").arg(year, month, "B" +  QString::number(Id));
    } else {
        // This is supposed to handle the error that occurs when a user inputs a wrong package type but no time. 
    }

    setCode(code_str);
    delete today;
}

float Package::getVolume(){
    return volume;
}

void Package::setVolume(float volume_c){
    volume = volume_c;
}

