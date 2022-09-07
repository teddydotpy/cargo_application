#ifndef CYLINDER_VIEW_H
#define CYLINDER_VIEW_H
#include <QGroupBox>

class QDoubleSpinBox;
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
        void newContainer(float diameter, float height, float weight);

    private slots:
        void clearBoxes();

    private:
        QDoubleSpinBox *diameter; 
        QDoubleSpinBox *height;
        QDoubleSpinBox *weight;

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