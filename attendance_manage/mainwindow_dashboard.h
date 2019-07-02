#ifndef MAINWINDOW_DASHBOARD_H
#define MAINWINDOW_DASHBOARD_H

#include <QMainWindow>
#include <QTime>          //2019.06.18 LJH
#include <QTimer>       //2019.06.18 LJH
#include <QSqlDatabase>     //2019.06.20 LJH
#include <QSerialPort>          //2019.06.26 LJH
#include "db_manager.h"     //2019.06.20 LJH
#include "dialog_staff_form.h"      //2019.06.18 LJH
#include "form_set_clock.h"     //2019.07.02    LJH

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
    QSerialPort *port;
    Dialog_staff_form *staff_form;
    Form_set_clock *clock_form;
    db_manager *database_1;
    QString read_string;
    QString set_clock_in;       //사용자가 설정한  출근시간.
    int selected_row;

private slots:
    void text_Reading();
    void setup_uart();
    void show_time();
    void on_tabWidget_tabBarClicked(int index);
    void on_pushButton_add_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton_del_clicked();
    void on_action_3_triggered();
    void on_action_triggered();
};

#endif // MAINWINDOW_DASHBOARD_H
