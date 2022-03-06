#ifndef HYPERBOLAV_H
#define HYPERBOLAV_H

#include <QWidget>
#include "hyperkanon.h"
#include "hyperravno.h"

namespace Ui {
class HyperbolaV;
}

class HyperbolaV : public QWidget
{
    Q_OBJECT

public:
    explicit HyperbolaV(QWidget *parent = nullptr);
    ~HyperbolaV();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::HyperbolaV *ui;
    hyperkanon *kan;
    hyperravno *rav;
};

#endif // HYPERBOLAV_H
