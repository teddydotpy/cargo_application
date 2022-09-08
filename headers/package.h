#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include <QJsonDocument>
#include <QList>

class Package{
        
    public:
        Package();
        Package(const Package &other);
        Package(int Id, int weight);
        ~Package();
        QString getCode();
        int getPallete();
        float getVolume();
        int getWeight();
        int getId();
        QList<int> *getDimensions();
        void setCode(QString code);
        void setPallete(int other_palette);
        void setVolume(float other_palette);
        void setWeight(int other_weight);
        void generatePackageCode(QChar packageType);

        void setDimensions(int diameter, int height);
        void setDimensions(int length, int breadth, int height);

    protected:
        float volume;

    private:
        QString package_code;
        int pallete;
        int weight, Id;
        QList<int> *dimensions;

};

#endif