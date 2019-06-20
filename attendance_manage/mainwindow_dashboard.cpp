#include "mainwindow_dashboard.h"
#include "ui_mainwindow_dashboard.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //시간 출력용 코드 2019.06.18
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(show_time()));
    timer->start(1000);

    show_time();
    //--------------------------------------
    //데이터베이스 연결 코드 2019.06.20
    database_1 = new db_manager("attendance_mng");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_time(){
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QString date_text = date.toString("yyyy 년 MM 월 dd 일  dddd");
    QString time_text = time.toString("hh : mm : ss");

    ui->label_date->setText(date_text);
    ui->label_time->setText(time_text);
}

void MainWindow::on_pushButton_clicked()
{
    staff_form = new Dialog_staff_form(this);
    staff_form->show();
}
