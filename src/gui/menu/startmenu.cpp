#include "startmenu.h"

StartMenu::StartMenu(QWidget* parent): QWidget(parent)
{
    QFormLayout* layout = new QFormLayout(this);

    range = new QLineEdit("1", this);
    steps = new QLineEdit("40", this);

    QValidator* rangeVal = new QIntValidator(0, 20, this);
    QValidator* stepsVal = new QIntValidator(BLOCK_SIZE*(FIELD_WIDTH+FIELD_HEIGHT)-2, 9999, this);

    range->setValidator(rangeVal);
    steps->setValidator(stepsVal);

    layout->addRow("Character sight range:",range);
    layout->addRow("Number of turns given:",steps);

    button = new QPushButton("Start",this);
    button->setDefault(true);

    this->layout()->addWidget(button);
}

StartMenu::~StartMenu(){
    std::cout << "Menu is being deleted" << std::endl;
}
