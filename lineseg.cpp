#include "lineseg.h"
#include "ui_lineseg.h"

lineSeg::lineSeg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lineSeg)
{
    ui->setupUi(this);
}

lineSeg::~lineSeg()
{
    delete ui;
}

void lineSeg::on_pushButton_clicked()
{
    //считываем данные с полей
    double A,B;
    QString AA=ui->lineEdit->text();
    QString BB=ui->lineEdit_2->text();
    bool ok;
    A=AA.toDouble(&ok);
    B=BB.toDouble(&ok);

    double a = -4, b =  4; //Начало и Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг пробега по Ox
    int N=(b-a)/h + 2; //Вычисляем количество отрисовываемых точек

    QVector<double> x(N), y(N); //Массивы координат точек
    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    if(B!=0&&A!=0)
    {
    //Вычисляем наши данные
    int i=0;
    for (double X=a; X<=b; X+=h)
    {
        x[i] = X;
        y[i] = B*(1-X/A);//Формула нашей функции
        i++;
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики и добавляем один график в widget
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);//Говорим, что отрисовать нужно график по нашим двум массивам x и y

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox
    double minY = y[0], maxY = y[0]; //Для оси Oy вычисляем минимальное и максимальное значение в векторах
    for (int i=1; i<N; i++)
    {
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
    }
    else
    {
        QMessageBox::about(this,"Ошибка","Такого графика не существует");
    }
}

