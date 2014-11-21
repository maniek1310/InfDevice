#ifndef INFDEVICE_H
#define INFDEVICE_H

#include <QMainWindow>
#include <QDebug>
#include "cpuid.h"
#include <math.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class InfDevice;
}

class InfDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfDevice(QWidget *parent = 0);
    ~InfDevice();
    Ui::InfDevice *ui;

private:

};

#endif // INFDEVICE_H
