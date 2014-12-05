#include "add_user.h"
#include "ui_add_user.h"

add_user::add_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_user)
{
    ui->setupUi(this);

    ui->label->setVisible(true);
    ui->lineEdit->setVisible(true);
}

add_user::~add_user()
{
    delete ui;
}

void add_user::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Ok)
        qDebug() << "tak" << endl;
    else if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Cancel)
        qDebug() << "nie" << endl;
    else if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Apply)
        qDebug() << "apply" << endl;
}
