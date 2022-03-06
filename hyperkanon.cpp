#include "hyperkanon.h"
#include "ui_hyperkanon.h"
#include <QMessageBox>
#include <QtCore>//библиотека математических функций

hyperkanon::hyperkanon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hyperkanon)
{
    ui->setupUi(this);
}

hyperkanon::~hyperkanon()
{
    delete ui;
}

void hyperkanon::on_pushButton_clicked()
{
        //считаем наши данные с полей
        double A, B;
        QString AA=ui->lineEdit->text();
        QString BB=ui->lineEdit_2->text();
        bool ok; //Используем далее ссылку на булевую переменную, чтобы узнать, прпвильно ли у нас произошла операция
        A=AA.toDouble(&ok);
        B=BB.toDouble(&ok);

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
            y1[i] =-(B/A)*qSqrt(X*X-A*A) ;//Формула нашей функции
            i++;
        }
        for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
        {
            x1[i] = X;
            y1[i] =(B/A)*qSqrt(X*X-A*A);//Формула нашей функции
            i++;
        }

        for (double X=a; X<0; X+=h)//Пробегаем по всем точкам
        {
            x2[j] = X;
            y2[j] =(B/A)*qSqrt(X*X-A*A) ;//Формула нашей функции
            j++;
        }
        for (double X=0; X<=b; X+=h)//Пробегаем по всем точкам
        {
            x2[j] = X;
            y2[j] =-(B/A)*qSqrt(X*X-A*A);//Формула нашей функции
            j++;
        }

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        ui->widget->addGraph();//Добавляем один график в widget
        ui->widget->graph(0)->setData(x1,y1); //Говорим, что отрисовать нужно график по нашим двум массивам x1 и y1
        ui->widget->addGraph();
        ui->widget->graph(1)->setData(x2,y2);

        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox
        //Для оси Oy вычислим минимальное и максимальное значение в векторах
        double minY = y2[0], maxY = y2[0];
        for (int i=1; i<N; i++)
        {
            if (y2[i]<minY) minY = y2[i];
            if (y2[i]>maxY) maxY = y2[i];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy
        ui->widget->replot(); //Перерисуем график на нашем widget
        }
        else {QMessageBox::about(this,"Ошибка","График не может быть построен.");}

}

