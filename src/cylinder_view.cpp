#include "../headers/cylinder_view.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>

CylinderView::CylinderView(QWidget *parent)
    :QGroupBox(parent){
    setupMainWidget();
    connect(add_box_button, SIGNAL(clicked()), this, SLOT(clearBoxes()));
}

CylinderView::~CylinderView(){

}

void CylinderView::setupMainWidget(){
    main_layout = new QVBoxLayout(this);

    diameter_layout = new QHBoxLayout();
    height_layout = new QHBoxLayout();
    weight_layout = new QHBoxLayout();

    diameter = new QSpinBox(this); 
    height = new QSpinBox(this); 
    weight = new QSpinBox(this); 

    main_label = new QLabel("Cylinder Container", this, Qt::WindowFlags());
    diameter_label = new QLabel("Diameter", this, Qt::WindowFlags());
    height_label = new QLabel("Height", this, Qt::WindowFlags());
    weight_label = new QLabel("Weight", this, Qt::WindowFlags());

    add_box_button = new QPushButton("Add Cylinder", this);

    diameter_layout->addWidget(diameter_label);
    diameter_layout->addWidget(diameter);

    height_layout->addWidget(height_label);
    height_layout->addWidget(height);

    weight_layout->addWidget(weight_label);
    weight_layout->addWidget(weight);

    main_layout->addWidget(main_label);
    main_layout->addItem(diameter_layout);
    main_layout->addItem(height_layout);
    main_layout->addItem(weight_layout);
    main_layout->addWidget(add_box_button);
}

void CylinderView::clearBoxes(){
    emit newContainer(diameter->value(), height->value(), weight->value());
    diameter->setValue(0);
    height->setValue(0);
    weight->setValue(0);
    this->update();
}