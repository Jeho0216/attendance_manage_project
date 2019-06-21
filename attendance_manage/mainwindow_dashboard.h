#ifndef MAINWINDOW_DASHBOARD_H
#define MAINWINDOW_DASHBOARD_H

#include <QMainWindow>
#include <QTime>          //2019.06.18 LJH
#include <QTimer>       //2019.06.18 LJH
#include <QSqlDatabase>     //2019.06.20 LJH
#include "db_manager.h"     //2019.06.20 LJH
#include "dialog_staff_form.h"      //2019.06.18 LJH

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog_staff_form *staff_form;
    db_manager *database_1;

private slots:
    void show_time();
    void on_pushButton_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_add_clicked();
};

#endif // MAINWINDOW_DASHBOARD_H
