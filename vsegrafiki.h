#ifndef VSEGRAFIKI_H
#define VSEGRAFIKI_H

#include <QWidget>
#include "parabalav.h"
#include "beeline.h"
#include "hyperbolav.h"
#include "ellipse.h"
#include "circl.h"

namespace Ui {
class vsegrafiki;
}

class vsegrafiki : public QWidget
{
    Q_OBJECT

public:
    explicit vsegrafiki(QWidget *parent = nullptr);
    ~vsegrafiki();

private slots:
    void on_parabola_clicked();

    void on_beelineB_clicked();

    void on_hyperbolaB_clicked();

    void on_ellipseB_clicked();

    void on_circleB_clicked();

private:
    Ui::vsegrafiki *ui;
    parabalaV *par;
    beeline *bee;
    HyperbolaV *hyp;
    ellipse *ell;
    circl *cir;
};

#endif // VSEGRAFIKI_H
