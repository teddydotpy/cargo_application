#include "../headers/box_view.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>

BoxView::BoxView(QWidget *parent)
    :QGroupBox(parent){
    setupMainWidget();

    connect(add_box_button, SIGNAL(clicked()), this, SLOT(clearBoxes()));
}

BoxView::~BoxView(){
}

void BoxView::setupMainWidget(){
    main_layout = new QVBoxLayout(this);

    length_layout = new QHBoxLayout();
    breadth_layout = new QHBoxLayout();
    height_layout = new QHBoxLayout();
    weight_layout = new QHBoxLayout();

    length = new  QDoubleSpinBox(this); 
    breadth = new QDoubleSpinBox(this); 
    height = new QDoubleSpinBox(this); 
    weight = new QDoubleSpinBox(this); 

    main_label = new QLabel("Box Container", this, Qt::WindowFlags());
    length_label = new QLabel("Length", this, Qt::WindowFlags());
    breadth_label = new QLabel("Breadth", this, Qt::WindowFlags());
    height_label = new QLabel("Height", this, Qt::WindowFlags());
    weight_label = new QLabel("Weight", this, Qt::WindowFlags());

    add_box_button = new QPushButton("Add Box", this);

    length_layout->addWidget(length_label);
    length_layout->addWidget(length);

    breadth_layout->addWidget(breadth_label);
    breadth_layout->addWidget(breadth);

    height_layout->addWidget(height_label);
    height_layout->addWidget(height);

    weight_layout->addWidget(weight_label);
    weight_layout->addWidget(weight);

    main_layout->addWidget(main_label);
    main_layout->addItem(length_layout);
    main_layout->addItem(breadth_layout);
    main_layout->addItem(height_layout);
    main_layout->addItem(weight_layout);
    main_layout->addWidget(add_box_button);
}

void BoxView::clearBoxes(){
    emit newContainer(length->value(), breadth->value(), height->value(), weight->value());
    length->setValue(0.0);
    breadth->setValue(0.0);
    height->setValue(0.0);
    weight->setValue(0.0);
    this->update();
}