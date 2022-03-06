#ifndef HYPERRAVNO_H
#define HYPERRAVNO_H

#include <QWidget>

namespace Ui {
class hyperravno;
}

class hyperravno : public QWidget
{
    Q_OBJECT

public:
    explicit hyperravno(QWidget *parent = nullptr);
    ~hyperravno();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hyperravno *ui;
};

#endif // HYPERRAVNO_H
