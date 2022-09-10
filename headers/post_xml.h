#ifndef POST_XML_H
#define POST_XML_H

#include <QWidget>

#include "package.h"
#include "allocated_packages.h"

class QPushButton;
class AllocatedMap;
class QVBoxLayout;
class QHBoxLayout;
class QTextEdit;
class QString;
class QLabel;
class QListWidget;
class NetworkClient;
class PostXmlWidget : public QWidget{
        Q_OBJECT
        /* I genuinely tried to be consistent with my naming conventions but oowowowowo */

    private:
        static PostXmlWidget *this_widget;
        PostXmlWidget(QWidget *parent)
            :QWidget(parent){
        setupView();

    };

        AllocatedMap *packages;
        QVBoxLayout *main_layout, *post_button, *top_layout, *bottom_layout;
        QHBoxLayout *button_layout, *server_buttons;
        QPushButton *post_b, *deallocate, *serialize, *connect_button;
        QTextEdit *xml_view;
        QListWidget *allocated_view;  
        QLabel *top_label, *bottom_label;
        QString *xml_output, *to_be_posted;
        NetworkClient *sendSocket;

        void setupView();

    public:
        ~PostXmlWidget();
        static PostXmlWidget *getInstance(QWidget *parent){
            // We want only one container widget to exist ever.
            if(!this_widget){
                this_widget = new PostXmlWidget(parent);
            }
            return this_widget;
        };

        void handleNoData();
        void handleNewAllocated();
        void handleEmptyList();

    signals:
        void unallocatePackage(Package *cont, int pos);
        void updateXmlViewer();
        void updateStatus(QString msg);
        void deallocatePackage(Package *obj);

    public slots:
        void SerializeXml();
        void recieveAllocatedPackages(AllocatedMap *map);
        void updateXml();
        void handleDeallocation();
        void sendXMl();
        void connectToServer();

};

#endif 