#include "beeline.h"
#include "ui_beeline.h"

beeline::beeline(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::beeline)
{
    ui->setupUi(this);
}

beeline::~beeline()
{
    delete ui;
}

void beeline::on_pushButton_clicked()
{
    gen=new lineGEN(this);
    gen->show();
}


void beeline::on_pushButton_2_clicked()
{
    seg=new lineSeg(this);
    seg->show();
}


void beeline::on_pushButton_3_clicked()
{
    slop=new lineSLOPE(this);
    slop->show();
}

