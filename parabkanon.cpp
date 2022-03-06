#include "parabkanon.h"
#include "ui_parabkanon.h"
#include <QMessageBox>

Parabkanon::Parabkanon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Parabkanon)
{
    ui->setupUi(this);
}

Parabkanon::~Parabkanon()
{
    delete ui;
}

void Parabkanon::on_pushButton_clicked()
{
        //считаем наши данные с полей
        double P;
        QString PP=ui->lineEdit->text();
        bool ok; //Используем далее ссылку на булевую переменную, чтобы узнать, прпвильно ли у нас произошла операция
        P=PP.toDouble(&ok);

        double a = -4; //Начало интервала, где рисуем график по оси Oy
        double b =  4; //Конец интервала, где рисуем график по оси Oy
        double h = 0.01; //Шаг, с которым будем пробегать по оси Oy
        int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

        QVector<double> x(N), y(N); //Массивы координат точек
        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");

        if(P!=0)
        {
        //Вычисляем наши данные
        int i=0;
        for (double Y=a; Y<=b; Y+=h)//Пробегаем по всем точкам
        {
            x[i] = Y*Y/(2*P);
            y[i] = Y;//Формула нашей функции
            i++;
        }

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        ui->widget->addGraph();//Добавляем один график в widget

        ui->widget->graph(0)->setData(x, y); //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        //Установим область, которая будет показываться на графике
        ui->widget->yAxis->setRange(a, b);//Для оси Oy
        //Для оси Ox вычислим минимальное и максимальное значение в векторах
        double minX = x[0], maxX = x[0];
        for (int i=1; i<N; i++)
        {
            if (x[i]<minX) minX = x[i];
            if (x[i]>maxX) maxX = x[i];
        }
        ui->widget->xAxis->setRange(minX, maxX);//Для оси Ox
        ui->widget->replot(); //Перерисуем график на нашем widget
        }
        else
        {QMessageBox::about(this,"Ошибка","График не может быть построен.");}
}



