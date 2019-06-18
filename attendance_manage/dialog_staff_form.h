#ifndef DIALOG_STAFF_FORM_H
#define DIALOG_STAFF_FORM_H

#include <QDialog>
#include <QMessageBox>      //2019.06.18 LJH

namespace Ui {
class Dialog_staff_form;
}

class Dialog_staff_form : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_staff_form(QWidget *parent = nullptr);
    ~Dialog_staff_form();

private slots:
    void on_pushButton_accept_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Dialog_staff_form *ui;

};

#endif // DIALOG_STAFF_FORM_H
