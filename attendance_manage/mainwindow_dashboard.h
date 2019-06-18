#ifndef MAINWINDOW_DASHBOARD_H
#define MAINWINDOW_DASHBOARD_H

#include <QMainWindow>
#include <QTime>          //2019.06.18 LJH
#include <QTimer>       //2019.06.18 LJH

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

private slots:
    void show_time();
};

#endif // MAINWINDOW_DASHBOARD_H
