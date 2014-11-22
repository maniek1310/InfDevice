#ifndef INFDEVICE_H
#define INFDEVICE_H

#include <QMainWindow>
#include <QDebug>
#include "cpuid.h"
#include <math.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeWidgetItem>

namespace Ui {
class InfDevice;
}

class InfDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfDevice(QWidget *parent = 0);
    ~InfDevice();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void insert_treewidget_item(QString text, int column, QString text2, int column2);

private:
    Ui::InfDevice *ui;
};

#endif // INFDEVICE_H
