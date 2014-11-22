#include "infdevice.h"
#include "ui_infdevice.h"

InfDevice::InfDevice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InfDevice)
{
    ui->setupUi(this);

    cpuid::view_info();

    // ustawienie layout`u aplikacji

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(ui->treeWidget);
    ui->treeWidget->setFixedWidth(180);
    hLayout->addWidget(ui->treeWidget_2);
    ui->centralWidget->setLayout(hLayout);
    ui->treeWidget_2->setColumnWidth(0, 160);
}

InfDevice::~InfDevice()
{
    delete ui;
}

void InfDevice::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString name_item = item->text(column);

    ui->treeWidget_2->clear();

    if(name_item == "Procesor")
    {
        QString cpu_producent = cpuid::VendorID_name(cpuid::VendorID()) + " (" + cpuid::VendorID() + ")";
        QString cpu_socket;

        unsigned long cpu_version_info = cpuid::Ver_info();
        unsigned long cpu_name_ext_family = cpuid::ext_family();
        unsigned long cpu_socket_find = cpuid::socket();
        unsigned long cpu_stepping;
        unsigned long cpu_model;
        unsigned long cpu_family;
        unsigned long cpu_ext_model;
        unsigned long cpu_ext_family;
        unsigned long ext_family;
        unsigned long socket;

        cpu_stepping = (cpu_version_info & 0xF);
        cpu_model = (cpu_version_info & 0xF0) >> 4;
        cpu_family = (cpu_version_info & 0xF00) >> 8;
        cpu_ext_model = (cpu_version_info & 0xF0000) >> 16;
        cpu_ext_family = (cpu_version_info & 0xF00000) >> 20;
        ext_family = (cpu_name_ext_family & 0x0FF00000) >> 20;
        socket = (cpu_socket_find & 0xF0000000) >> 28;

        if(ext_family == 0x1){                              // AMD K8L (Fam 10h)
                 if(socket == 0x0) cpu_socket = "Socket F";
            else if(socket == 0x1) cpu_socket = "Socket AM";
            else if(socket == 0x2) cpu_socket = "Socket S1";
            else if(socket == 0x3) cpu_socket = "Socket G34";
            else if(socket == 0x4) cpu_socket = "Socket ASB2";
            else if(socket == 0x5) cpu_socket = "Socket C32";
        }else if(ext_family == 0x3){                         // AMD K8L (Fam 12h)
                 if(socket == 0x1) cpu_socket = "Socket FS1 (µPGA)";
            else if(socket == 0x2) cpu_socket = "Socket FM1 (PGA)";
        }else if(ext_family == 0x5){                         // AMD BC (Fam 14h)
            if(socket == 0x0) cpu_socket = "Socket FT1 (BGA)";
        }else if(ext_family == 0x6 && cpu_ext_model == 0x0){ // AMD BD (Fam 15h) ext_model 0
                 if(socket == 0x1) cpu_socket = "Socket AM3";
            else if(socket == 0x3) cpu_socket = "Socket G34";
            else if(socket == 0x5) cpu_socket = "Socket C32";
        }else if(ext_family == 0x6 && cpu_ext_model == 0x1){ // AMD BD (Fam 15h) ext_model 1
                 if(socket == 0x0) cpu_socket = "Socket FP2 (BGA)";
            else if(socket == 0x1) cpu_socket = "Socket FS1r2 (µPGA)";
            else if(socket == 0x2) cpu_socket = "Socket FM2 (PGA)";
        }else if(ext_family = 0x6 && cpu_ext_model == 0x3){ // AMD BD (Fam 15h) ext_model 3
                 if(socket == 0x0) cpu_socket = "Socket FP3 (BGA)";
            else if(socket == 0x1) cpu_socket = "Socket FM2r2 (µPGA)";
        }else if(ext_family == 0x7 && cpu_ext_model == 0x0){ // AMD JG (Fam 16h) ext_model 0
                 if(socket == 0x0) cpu_socket = "Socket FT3 (BGA)";
            else if(socket == 0x1) cpu_socket = "SocketFS1b";
        }else if(ext_family == 0x7 && cpu_ext_model == 0x3){ // AMD JG (Fam 16h) ext_model 3
                 if(socket == 0x0) cpu_socket = "Socket FT3b (BGA)";
            else if(socket == 0x3) cpu_socket = "Socket FP4";
        }

        insert_treewidget_item("Producent procesora : ", 0, cpu_producent, 1);
        insert_treewidget_item("Nazwa procesora : ", 0, cpuid::Brand(), 1);
        insert_treewidget_item("Stepping : ", 0, QString::number(cpu_stepping), 1);
        insert_treewidget_item("Model : ", 0, QString::number(cpu_model), 1);
        insert_treewidget_item("Family : ", 0, QString::number(cpu_family), 1);
        insert_treewidget_item("Extended model : ", 0, QString::number(cpu_ext_model), 1);
        insert_treewidget_item("Extended family : ", 0, QString::number(cpu_ext_family), 1);
        insert_treewidget_item("Socket : ", 0, cpu_socket, 1);
    }
}

void InfDevice::insert_treewidget_item(QString text, int column, QString text2, int column2)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget_2);
    item->setText(column, text);
    item->setText(column2, text2);
}
