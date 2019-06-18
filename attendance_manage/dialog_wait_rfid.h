#ifndef DIALOG_WAIT_RFID_H
#define DIALOG_WAIT_RFID_H

#include <QDialog>

namespace Ui {
class Dialog_wait_rfid;
}

class Dialog_wait_rfid : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_wait_rfid(QWidget *parent = nullptr);
    ~Dialog_wait_rfid();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_wait_rfid *ui;
    QWidget *staff_form;
};

#endif // DIALOG_WAIT_RFID_H
