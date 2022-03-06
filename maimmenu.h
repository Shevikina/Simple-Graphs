#ifndef MAIMMENU_H
#define MAIMMENU_H

#include <QMainWindow>

namespace Ui {
class MaimMenu;
}

class MaimMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MaimMenu(QWidget *parent = nullptr);
    ~MaimMenu();

private:
    Ui::MaimMenu *ui;
};

#endif // MAIMMENU_H
