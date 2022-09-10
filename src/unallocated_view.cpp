#include "../headers/unallocated_view.h"

#include <QString>
#include <QGroupBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QList>
#include <QDebug>

UncallocatedView::UncallocatedView(QWidget *parent)
    :QGroupBox(parent){
    setupView();

    connect(move_button, SIGNAL(clicked()), this, SLOT(removeItem()));
}

UncallocatedView::~UncallocatedView(){
}

void UncallocatedView::setupView(){

    main_layout = new QHBoxLayout(this);
    left_layout = new QVBoxLayout();
    right_layout = new QVBoxLayout();

    list_widget = new QListWidget(this);

    list_label = new QLabel("List of unallocated containers", this, Qt::WindowFlags());
    paletter_label = new QLabel("Click on item in list, choose a palette number \nand move the container to that pallete.", this, Qt::WindowFlags());
    paletter_spin = new QSpinBox(this);
    move_button = new QPushButton("Move to Palette", this);
    backup_button = new QPushButton("Backup", this);
    restore_button = new QPushButton("Restore", this);

    move_button->setMinimumWidth(250);
    paletter_spin->setRange(1, 200);

    left_layout->addWidget(list_label);
    left_layout->addSpacing(10);
    left_layout->addWidget(list_widget);

    right_layout->addWidget(paletter_label);
    right_layout->addWidget(paletter_spin);
    right_layout->addSpacing(10);
    right_layout->addWidget(move_button);
    right_layout->addSpacing(25);

    cr_buttons = new QHBoxLayout(); 
    cr_buttons->addWidget(backup_button);
    cr_buttons->addWidget(restore_button);

    right_layout->addItem(cr_buttons);
    main_layout->addItem(left_layout);
    main_layout->addSpacing(15);
    main_layout->addItem(right_layout);
}

void UncallocatedView::update(QString code){
    list_widget->addItem(code);
}

void UncallocatedView::removeItem(){
    QList<QListWidgetItem*> selected = list_widget->selectedItems();
    QModelIndexList index = list_widget->selectionModel()->selectedIndexes();
    if (selected.length() == 1){
        emit codeSelected(paletter_spin->value(), index[0].row());
        qDeleteAll(selected);
    } else {
        emit updateStatus("You should not select multiple things please.");
    }
}

