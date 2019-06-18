#ifndef DIALOG_LOGIN_H
#define DIALOG_LOGIN_H

#include <QDialog>
#include <QMessageBox>      //2019.06.18 LJH
#include "mainwindow_dashboard.h"       //2019.06.18 LJH

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::Dialog *ui;
    MainWindow *main_dashboard;
};

#endif // DIALOG_LOGIN_H
