#ifndef BEELINE_H
#define BEELINE_H

#include <QWidget>
#include "linegen.h"
#include "lineseg.h"
#include "lineslope.h"

namespace Ui {
class beeline;
}

class beeline : public QWidget
{
    Q_OBJECT

public:
    explicit beeline(QWidget *parent = nullptr);
    ~beeline();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::beeline *ui;
    lineGEN *gen;
    lineSeg *seg;
    lineSLOPE *slop;
};

#endif // BEELINE_H
