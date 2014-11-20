#include "infdevice.h"
#include "ui_infdevice.h"

InfDevice::InfDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfDevice)
{
    ui->setupUi(this);

    cpuid::VendorID();
}

InfDevice::~InfDevice()
{
    delete ui;
}
