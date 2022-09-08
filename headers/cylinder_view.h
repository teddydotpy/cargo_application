#ifndef CYLINDER_VIEW_H
#define CYLINDER_VIEW_H
#include <QGroupBox>

class QSpinBox;
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

class CylinderView: public QGroupBox{
        Q_OBJECT
    public:
        CylinderView(QWidget *parent);
        ~CylinderView();

        void setupMainWidget();
    signals:
        void newContainer(int diameter, int height, int weight);

    private slots:
        void clearBoxes();

    private:
        QSpinBox *diameter; 
        QSpinBox *height;
        QSpinBox *weight;

        // Labels 
        QLabel *main_label;
        QLabel *diameter_label;
        QLabel *height_label;
        QLabel *weight_label;

        // button
        QPushButton *add_box_button; 

        // Layouts
        QVBoxLayout *main_layout;

        QHBoxLayout *diameter_layout;
        QHBoxLayout *height_layout;
        QHBoxLayout *weight_layout;
};

#endif