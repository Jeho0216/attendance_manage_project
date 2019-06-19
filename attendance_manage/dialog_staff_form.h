#ifndef DIALOG_STAFF_FORM_H
#define DIALOG_STAFF_FORM_H

#include <QDialog>
#include <QMessageBox>      //2019.06.18 LJH
#include <QSerialPort>          //2019.06.19 LJH
#include <QDebug>
#include <QTimer>
#include <QSqlDatabase>     //2019.06.19 LJH
#include "db_manager.h"     //2019.06.19 LJH

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

    //UART용 변수
    QSerialPort *port;
    QString read_string;

    //DB용 변수
    db_manager *database_1;

private slots:
    void text_Reading();

    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_card_clicked();

    void setup_uart();

    void on_pushButton_rfid_con_clicked();

private:
    Ui::Dialog_staff_form *ui;
    QWidget *dashboard;
};

#endif // DIALOG_STAFF_FORM_H
