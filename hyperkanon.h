#ifndef HYPERKANON_H
#define HYPERKANON_H

#include <QWidget>

namespace Ui {
class hyperkanon;
}

class hyperkanon : public QWidget
{
    Q_OBJECT

public:
    explicit hyperkanon(QWidget *parent = nullptr);
    ~hyperkanon();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hyperkanon *ui;
};

#endif // HYPERKANON_H
