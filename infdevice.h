#ifndef INFDEVICE_H
#define INFDEVICE_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class InfDevice;
}

class InfDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfDevice(QWidget *parent = 0);
    ~InfDevice();

private:
    Ui::InfDevice *ui;
};

#endif // INFDEVICE_H
