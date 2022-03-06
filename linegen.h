#ifndef LINEGEN_H
#define LINEGEN_H

#include <QWidget>

namespace Ui {
class lineGEN;
}

class lineGEN : public QWidget
{
    Q_OBJECT

public:
    explicit lineGEN(QWidget *parent = nullptr);
    ~lineGEN();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineGEN *ui;
};

#endif // LINEGEN_H
