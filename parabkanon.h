#ifndef PARABKANON_H
#define PARABKANON_H

#include <QWidget>

namespace Ui {
class Parabkanon;
}

class Parabkanon : public QWidget
{
    Q_OBJECT

public:
    explicit Parabkanon(QWidget *parent = nullptr);
    ~Parabkanon();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Parabkanon *ui;
};

#endif // PARABKANON_H
