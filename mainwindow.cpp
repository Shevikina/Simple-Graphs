#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_postroit_clicked()
{
    //считаем наши данные с полей
    double A, B, C;
    QString AA=ui->Aline->text();
    QString BB=ui->Bline->text();
    QString CC=ui->Cline->text();
    bool ok; //Используем далее ссылку на булевую переменную, чтобы узнать, прпвильно ли у нас произошла операция
    A=AA.toDouble(&ok);
    B=BB.toDouble(&ok);
    C=CC.toDouble(&ok);

        double a = -4; //Начало интервала, где рисуем график по оси Ox
        double b =  4; //Конец интервала, где рисуем график по оси Ox
        double h = 0.01; //Шаг, с которым будем пробегать по оси Ox
        int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

        QVector<double> x(N), y(N); //Массивы координат точек
        //Подписываем оси Ox и Oy
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        if(A!=0)
        {
        //Вычисляем наши данные
        int i=0;
        for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
        {
            x[i] = X;
            y[i] = A*X*X+B*X+C;//Формула нашей функции
            i++;
        }

        ui->widget->clearGraphs();//Если нужно, но очищаем все графики
        ui->widget->addGraph();//Добавляем один график в widget

        ui->widget->graph(0)->setData(x, y); //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        //Установим область, которая будет показываться на графике
        ui->widget->xAxis->setRange(a, b);//Для оси Ox
        //Для оси Oy вычислим минимальное и максимальное значение в векторах
        double minY = y[0], maxY = y[0];
        for (int i=1; i<N; i++)
        {
            if (y[i]<minY) minY = y[i];
            if (y[i]>maxY) maxY = y[i];
        }
        ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy
        ui->widget->replot(); //Перерисуем график на нашем widget
        }
        else
        { QMessageBox::about(this,"Ошибка","В квадратном уравнении коэффициент перед x^2 не может ровняться 0.");}
}




