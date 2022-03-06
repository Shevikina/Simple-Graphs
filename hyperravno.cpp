#include "hyperravno.h"
#include "ui_hyperravno.h"
#include <QMessageBox>

hyperravno::hyperravno(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hyperravno)
{
    ui->setupUi(this);
}

hyperravno::~hyperravno()
{
    delete ui;
}

void hyperravno::on_pushButton_clicked()
{
    //считаем наши данные с полей
    double K;
    QString KK=ui->lineEdit->text();
    bool ok; //Используем далее ссылку на булевую переменную, чтобы узнать, прпвильно ли у нас произошла операция
    K=KK.toDouble(&ok);

    double a = -4; //Начало интервала, где рисуем график по оси Ox
    double b =  4; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

    QVector<double> x(N), y(N); //Массивы координат точек
   // QVector<double> x2(N),y2(N);
    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    if(K!=0)
    {
    //Вычисляем наши данные
    int i=0;
    for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
    {
        x[i] = X;
        y[i] =K/X ;//Формула нашей функции
        i++;
    }
    for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x[i] = X;
        y[i] =K/X;//Формула нашей функции
        i++;
    }

    ui->widget->clearGraphs();//Если нужно, но очищаем все графики
    ui->widget->addGraph();//Добавляем один график в widget
    ui->widget->graph(0)->setData(x,y); //Говорим, что отрисовать нужно график по нашим двум массивам x1 и y1

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox
    ui->widget->yAxis->setRange(a, b);//Для оси Oy
    ui->widget->replot(); //Перерисуем график на нашем widget
    }
    else {QMessageBox::about(this,"Ошибка","График не может быть построен.");}
}

