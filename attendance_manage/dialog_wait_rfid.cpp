#include "dialog_wait_rfid.h"
#include "ui_dialog_wait_rfid.h"

Dialog_wait_rfid::Dialog_wait_rfid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_wait_rfid)
{
    ui->setupUi(this);
    staff_form = parent;
    staff_form->setEnabled(false);
    this->setEnabled(true);
}

Dialog_wait_rfid::~Dialog_wait_rfid()
{
    staff_form->setEnabled(true);
    delete ui;
}

void Dialog_wait_rfid::on_pushButton_clicked()
{
    staff_form->setEnabled(true);
    this->close();
}

void Dialog_wait_rfid::closeEvent(QCloseEvent *event){
    staff_form->setEnabled(true);
    this->close();
}
