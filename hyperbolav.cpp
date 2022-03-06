#include "hyperbolav.h"
#include "ui_hyperbolav.h"

HyperbolaV::HyperbolaV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HyperbolaV)
{
    ui->setupUi(this);
}

HyperbolaV::~HyperbolaV()
{
    delete ui;
}

void HyperbolaV::on_pushButton_clicked()
{
    kan=new hyperkanon(this);
    kan->show();
}


void HyperbolaV::on_pushButton_2_clicked()
{
    rav=new hyperravno(this);
    rav->show();
}

