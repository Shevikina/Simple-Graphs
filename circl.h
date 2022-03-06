#ifndef CIRCL_H
#define CIRCL_H

#include <QWidget>

namespace Ui {
class circl;
}

class circl : public QWidget
{
    Q_OBJECT

public:
    explicit circl(QWidget *parent = nullptr);
    ~circl();

private slots:
    void on_pushButton_clicked();

private:
    Ui::circl *ui;
};

#endif // CIRCL_H
