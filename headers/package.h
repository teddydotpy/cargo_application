#ifndef PACKAGE_H
#define PACKAGE_H

#include <QString>
#include <QJsonDocument>

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
        void setCode(QString code);
        void setPallete(int other_palette);
        void setVolume(float other_palette);
        void setWeight(int other_weight);
        void generatePackageCode(QChar packageType);

    protected:
        int volume;

    private:
        QString package_code;
        int pallete;
        int weight, Id;
        float volume;
};

#endif