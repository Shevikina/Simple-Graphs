#ifndef LINESLOPE_H
#define LINESLOPE_H

#include <QWidget>

namespace Ui {
class lineSLOPE;
}

class lineSLOPE : public QWidget
{
    Q_OBJECT

public:
    explicit lineSLOPE(QWidget *parent = nullptr);
    ~lineSLOPE();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineSLOPE *ui;
};

#endif // LINESLOPE_H
