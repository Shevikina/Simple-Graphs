#include "maimmenu.h"
#include "ui_maimmenu.h"

MaimMenu::MaimMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MaimMenu)
{
    ui->setupUi(this);
}

MaimMenu::~MaimMenu()
{
    delete ui;
}
