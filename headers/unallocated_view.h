#ifndef UNALLOCATED_VIEW_H
#define UNALLOCATED_VIEW_H

#include <QGroupBox>

class QString;
class QSpinBox;
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QListWidget;

class UncallocatedView : public QGroupBox{
    Q_OBJECT
    public:
        UncallocatedView(QWidget *parent);
        ~UncallocatedView();

        void setupView();
        
    signals:
        void codeSelected(QString code, int palletteNo, int pos);
        void backup();
        void updateStatus(QString msg);
    
    public slots:
        void update(QString code);
        void removeItem();

    private:
        QLabel *list_label;
        QLabel *paletter_label;

        QSpinBox *paletter_spin;

        // Buttons 
        QPushButton *move_button;
        QPushButton *backup_button;
        QPushButton *restore_button;

        // Layouts
        QHBoxLayout *main_layout;
        QHBoxLayout *cr_buttons;
        QVBoxLayout *left_layout;
        QVBoxLayout *right_layout;

        QListWidget *list_widget;
};

#endif 