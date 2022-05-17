#ifndef STARTMENU_H
#define STARTMENU_H

#include <iostream>

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QFormLayout>
#include <QPushButton>

#include "src/defines.h"

class StartMenu: public QWidget
{
    Q_OBJECT
public:
    StartMenu(QWidget* parent = nullptr);
    QLineEdit* range;
    QLineEdit* steps;
    QPushButton* button;
    ~StartMenu();
};

#endif // STARTMENU_H
