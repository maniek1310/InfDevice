#ifndef ADD_USER_H
#define ADD_USER_H

#include <QDialog>
#include "infdevice.h"

namespace Ui {
class add_user;
}

class add_user : public QDialog
{
    Q_OBJECT

public:
    explicit add_user(QWidget *parent = 0);
    ~add_user();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::add_user *ui;
};

#endif // ADD_USER_H
