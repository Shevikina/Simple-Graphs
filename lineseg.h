#ifndef LINESEG_H
#define LINESEG_H

#include <QWidget>

namespace Ui {
class lineSeg;
}

class lineSeg : public QWidget
{
    Q_OBJECT

public:
    explicit lineSeg(QWidget *parent = nullptr);
    ~lineSeg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineSeg *ui;
};

#endif // LINESEG_H
