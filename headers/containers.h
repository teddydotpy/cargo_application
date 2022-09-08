#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <QWidget>

#include "unallocated_view.h"
#include "unallocated_list.h"
#include "allocated_packages.h"
#include "box_view.h"
#include "cylinder_view.h"

class QVBoxLayout;
class QString;
class ContainerWidget : public QWidget{
        Q_OBJECT

        /* 
            I probably should have created an intermediate handler function to get the back side to marry 
            the front side seamlessly, but I am all kinds of stressed out so I am sorry for the terrible design.         
        */

    private:
        static ContainerWidget *this_widget;
        ContainerWidget(QWidget *parent)
            : QWidget(parent){
                pkg_list = new UnallocatedList();
                allocateMap  = new AllocatedMap();
                box = new BoxView(this);
                cylinder  = new CylinderView(this);
                
                setupViews();
                connect(box, SIGNAL(newContainer(int, int, int, int)), this, SLOT(newPackage(int, int, int, int)));
                connect(cylinder, SIGNAL(newContainer(int, int, int)), this, SLOT(newPackage(int, int, int)));
                connect(this, SIGNAL(newContainer(QString)), code_list, SLOT(update(QString)));
                connect(code_list, SIGNAL(codeSelected(QString, int, int)), this, SLOT(paletteUpdate(QString, int, int)));
            };

        QVBoxLayout *main_layout;
        QHBoxLayout *top_layout;

        BoxView *box;
        CylinderView *cylinder;
        UncallocatedView *code_list;
        UnallocatedList *pkg_list;
        AllocatedMap *allocateMap;

        void setupViews();
    public:
        ~ContainerWidget();
        static ContainerWidget *getInstance(QWidget *parent){
            // We want only one container widget to exist ever.
            if(!this_widget){
                this_widget = new ContainerWidget(parent);
            }
            return this_widget;
        };

    public slots:
        void newPackage(int diameter, int height, int weight);
        void newPackage(int length, int breadth, int height, int weight);
        void paletteUpdate(QString code, int palletteNo, int pos);

    signals:
        void newContainer(QString item);
        void updateStatus(QString item);
        void sendAllocatedMap(AllocatedMap *map);

};

#endif