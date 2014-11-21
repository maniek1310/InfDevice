#include "infdevice.h"
#include "ui_infdevice.h"

InfDevice::InfDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfDevice)
{
    ui->setupUi(this);

    cpuid::view_info();

    QHBoxLayout *hLayout = new QHBoxLayout;

    hLayout->addWidget(ui->treeWidget);

    ui->treeWidget->setFixedWidth(150);

    hLayout->addWidget(ui->treeWidget_2);
    ui->centralWidget->setLayout(hLayout);

}

InfDevice::~InfDevice()
{
    delete ui;
}
