#ifndef DIALOG_STAFF_FORM_H
#define DIALOG_STAFF_FORM_H

#include <QDialog>
#include <QMessageBox>      //2019.06.18 LJH
#include "dialog_wait_rfid.h"

namespace Ui {
class Dialog_staff_form;
}

class Dialog_staff_form : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_staff_form(QWidget *parent = nullptr);
    ~Dialog_staff_form();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_card_clicked();

private:
    Ui::Dialog_staff_form *ui;
    QWidget *dashboard;
    Dialog_wait_rfid *wait_rfid;
};

#endif // DIALOG_STAFF_FORM_H
