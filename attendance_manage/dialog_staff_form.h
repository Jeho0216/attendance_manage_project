#ifndef DIALOG_STAFF_FORM_H
#define DIALOG_STAFF_FORM_H

#include <QDialog>
#include <QMessageBox>      //2019.06.18 LJH
#include <QSerialPort>          //2019.06.19 LJH
#include <QDebug>
#include <QTimer>

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
