#ifndef INFDEVICE_H
#define INFDEVICE_H

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <LM.h>
#include <QMainWindow>
#include <QDebug>
#include "cpuid.h"
#include <math.h>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QAbstractButton>
#include <QTranslator>
#include "add_user.h"

#pragma comment(lib, "netapi32.lib")

#define Q(txt) QString::fromWCharArray(L##txt)

namespace Ui {
class InfDevice;
}

class InfDevice : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfDevice(QWidget *parent = 0);
    ~InfDevice();
    void addUser();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void insert_treewidget_item(QString text, int column, QString text2, int column2);

    void on_actionDodaj_triggered();

private:
    Ui::InfDevice *ui;
};

#endif // INFDEVICE_H
