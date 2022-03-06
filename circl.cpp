#include "circl.h"
#include "ui_circl.h"
#include <QMessageBox>
#include <QtCore>

circl::circl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::circl)
{
    ui->setupUi(this);
}

circl::~circl()
{
    delete ui;
}

void circl::on_pushButton_clicked()
{
    //считаем наши данные с полей
    double A, B, C;
    QString AA=ui->lineEdit->text();
    QString BB=ui->lineEdit_2->text();
    QString CC=ui->lineEdit_3->text();
    bool ok;
    A=AA.toDouble(&ok);
    B=BB.toDouble(&ok);
    C=CC.toDouble(&ok);

    double a = -5; //Начало интервала, где рисуем график по оси Ox
    double b =  5; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

    QVector<double> x1(N), y1(N),x2(N),y2(N); //Массивы координат точек
    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    if(C>0)
    {
    //Вычисляем наши данные
     int i=0, j=0;
    for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
    {
        x1[i] = X;
        y1[i] =B+qSqrt(C*C-(X-A)*(X-A)) ;//Формула нашей функции
        i++;
    }
    for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x1[i] = X;
        y1[i] =B-qSqrt(C*C-(X-A)*(X-A));//Формула нашей функции
        i++;
    }

    for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
    {
        x2[j] = X;
        y2[j] =B-qSqrt(C*C-(X-A)*(X-A)) ;//Формула нашей функции
        j++;
    }
    for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x2[j] = X;
        y2[j] =B+qSqrt(C*C-(X-A)*(X-A));//Формула нашей функции
        j++;
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    ui->widget->addGraph();//Добавляем один график в widget
    ui->widget->graph(0)->setData(x1,y1); //Говорим, что отрисовать нужно график по нашим двум массивам x1 и y1
    ui->widget->addGraph();
    ui->widget->graph(1)->setData(x2,y2);

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox
    ui->widget->yAxis->setRange(a-2, b+2);//Для оси Oy
    ui->widget->replot(); //Перерисуем график на нашем widget
    }
    else {QMessageBox::about(this,"Ошибка","График не может быть построен.");}
}

