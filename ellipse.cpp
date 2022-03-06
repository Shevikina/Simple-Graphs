#include "ellipse.h"
#include "ui_ellipse.h"
#include <QMessageBox>
#include <QtCore>

ellipse::ellipse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ellipse)
{
    ui->setupUi(this);
}

ellipse::~ellipse()
{
    delete ui;
}

void ellipse::on_pushButton_clicked()
{
    //считаем наши данные с полей
    double A, B, Q, P;
    QString AA=ui->lineEdit->text();
    QString BB=ui->lineEdit_2->text();
    QString QQ=ui->lineEdit_3->text();
    QString PP=ui->lineEdit_4->text();
    bool ok; //Используем далее ссылку на булевую переменную, чтобы узнать, прпвильно ли у нас произошла операция
    A=AA.toDouble(&ok);
    B=BB.toDouble(&ok);
    Q=QQ.toDouble(&ok);
    P=PP.toDouble(&ok);

    double a = -4; //Начало интервала, где рисуем график по оси Ox
    double b =  4; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

    QVector<double> x1(N), y1(N),x2(N),y2(N); //Массивы координат точек
    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    if(A>0&&B>0)
    {
    //Вычисляем наши данные
     int i=0, j=0;
    for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
    {
        x1[i] = X;
        y1[i] =P+(B/A)*qSqrt(A*A-(X-Q)*(X-Q)) ;//Формула нашей функции
        i++;
    }
    for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x1[i] = X;
        y1[i] =P-(B/A)*qSqrt(A*A-(X-Q)*(X-Q));//Формула нашей функции
        i++;
    }

    for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
    {
        x2[j] = X;
        y2[j] =P-(B/A)*qSqrt(A*A-(X-Q)*(X-Q)) ;//Формула нашей функции
        j++;
    }
    for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x2[j] = X;
        y2[j] =P+(B/A)*qSqrt(A*A-(X-Q)*(X-Q));//Формула нашей функции
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

