#ifndef PARABALAV_H
#define PARABALAV_H

#include <QWidget>
#include "mainwindow.h"
#include "parabkanon.h"

namespace Ui {
class parabalaV;
}

class parabalaV : public QWidget
{
    Q_OBJECT

public:
    explicit parabalaV(QWidget *parent = nullptr);
    ~parabalaV();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::parabalaV *ui;
    MainWindow *kvad;
    Parabkanon *kanon;
};

#endif // PARABALAV_H
