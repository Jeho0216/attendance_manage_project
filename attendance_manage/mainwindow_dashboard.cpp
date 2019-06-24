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

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 1){
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);        //테이블 수정(edit)불가 설정.
        database_1->print_staff(ui->tableWidget);
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    staff_form = new Dialog_staff_form(this, database_1, ui->tableWidget);
    staff_form->show();
}

//사원 목록에서 사원 이름을 클릭할 경우,
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString name, phone, card_id;
    QString *staff_info;

    if(column == 0){
        name = ui->tableWidget->currentItem()->text();
        phone = ui->tableWidget->item(row, 1)->text();
        qDebug() << "select name : " << name << endl;
        card_id = database_1->get_card_id(name, phone);      //입력한 이름에 대한 card_id 값 반환.

        staff_info = database_1->get_staff_info(card_id);       //입력받은 card_id를 가진 사원 정보 반환.
        ui->lineEdit_name->setText(staff_info[0]);
        ui->lineEdit_age->setText(staff_info[1]);
        ui->lineEdit_phone->setText(staff_info[2]);
        ui->lineEdit_card->setText(staff_info[3]);
    }
}
