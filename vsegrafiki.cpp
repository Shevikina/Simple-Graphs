#include "vsegrafiki.h"
#include "ui_vsegrafiki.h"


vsegrafiki::vsegrafiki(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vsegrafiki)
{
    ui->setupUi(this);
}

vsegrafiki::~vsegrafiki()
{
    delete ui;
}

void vsegrafiki::on_parabola_clicked()
{
    par=new parabalaV(this); //создаем переменную которую объявили в vsegrafiki.h
    par->show(); //открываем наше окно с выбором парабал
}


void vsegrafiki::on_beelineB_clicked()
{
    bee=new beeline(this);
    bee->show();
}


void vsegrafiki::on_hyperbolaB_clicked()
{
    hyp=new HyperbolaV(this);
    hyp->show();
}


void vsegrafiki::on_ellipseB_clicked()
{
    ell= new ellipse(this);
    ell->show();
}


void vsegrafiki::on_circleB_clicked()
{
    cir=new circl(this);
    cir->show();
}


