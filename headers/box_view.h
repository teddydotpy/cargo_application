#ifndef BOX_VIEW_H
#define BOX_VIEW_H
#include <QGroupBox>

class QSpinBox;
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

class BoxView: public QGroupBox{
        Q_OBJECT

    public:
        BoxView(QWidget *parent);
        ~BoxView();

        void setupMainWidget();

    signals:
        void newContainer(int length, int breadth, int height, int weight);

    private slots:
        void clearBoxes();

    private:
        QSpinBox *length; 
        QSpinBox *breadth;
        QSpinBox *height;
        QSpinBox *weight;

        // Labels 
        QLabel *main_label;
        QLabel *length_label;
        QLabel *breadth_label;
        QLabel *height_label;
        QLabel *weight_label;

        // button
        QPushButton *add_box_button; 

        // Layouts
        QVBoxLayout *main_layout;

        QHBoxLayout *length_layout;
        QHBoxLayout *breadth_layout;
        QHBoxLayout *height_layout;
        QHBoxLayout *weight_layout;
};

#endif