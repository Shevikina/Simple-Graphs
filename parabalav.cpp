#include "parabalav.h"
#include "ui_parabalav.h"


parabalaV::parabalaV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parabalaV)
{
    ui->setupUi(this);
}

parabalaV::~parabalaV()
{
    delete ui;
}

void parabalaV::on_pushButton_2_clicked()
{
    kvad=new MainWindow(this);
    kvad->show();
}


void parabalaV::on_pushButton_clicked()
{
    kanon=new Parabkanon(this);
    kanon->show();
}

