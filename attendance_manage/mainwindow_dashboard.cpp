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
    database_1->print_dashboard_list(ui->tableWidget_list);

    //시리얼 포트 추가 코드 2019.06.26
    port = new QSerialPort();
    setup_uart();
    QObject::connect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));

    //출근시간 초기화 2019.07.02
    set_clock_in = "0900";
    ui->label_clock_in->setText(set_clock_in.left(2) + "시 " + set_clock_in.right(2) + "분");

    //사원수 저장
    progress_bar_update();

    //테이블 디자인 조절
    ui->tableWidget->horizontalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");
    ui->tableWidget->verticalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");

    ui->tableWidget_list->horizontalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");
    ui->tableWidget_list->verticalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");
    ui->tableWidget_list->setColumnWidth(0, 100);
    ui->tableWidget_list->setColumnWidth(1, 200);
    ui->tableWidget_list->setColumnWidth(2, 200);
    ui->tableWidget_list->setColumnWidth(3, 30);

    ui->tableWidget_info->horizontalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");
    ui->tableWidget_info->verticalHeader()->setStyleSheet("color:rgb(242,242,242); background:rgb(93,132,166);");
    ui->tableWidget_info->setColumnWidth(0, 200);
    ui->tableWidget_info->setColumnWidth(1, 200);
    ui->tableWidget_info->setColumnWidth(2, 30);

    //Progress Bar 디자인 설정
    QString bar_in = "QProgressBar {border: 1px solid LightGray; border-radius : 5px; text-align : center;}"
                         "QProgressBar::chunk {background:rgb(93,132,166)}";
    QString bar_normal = "QProgressBar {border: 1px solid LightGray; border-radius : 5px; text-align : center;}"
                         "QProgressBar::chunk {background:rgb(43,127,57)}";
    QString bar_late = "QProgressBar {border: 1px solid LightGray; border-radius : 5px; text-align : center;}"
                       "QProgressBar::chunk {background:rgb(178,9,0)}";
    ui->progressBar_normal->setStyleSheet(bar_normal);
    ui->progressBar_in->setStyleSheet(bar_in);
    ui->progressBar_late->setStyleSheet(bar_late);
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
    else if(index == 0){
        connect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));      //dashboard text_Reading()

        progress_bar_update();

        ui->tableWidget_info->setRowCount(0);
        ui->tableWidget_info->setEditTriggers(QAbstractItemView::NoEditTriggers);        //테이블 수정(edit)불가 설정.
        database_1->print_dashboard_list(ui->tableWidget_list);

        qDebug() << "set_clock_in : " << set_clock_in << endl;

        ui->label_clock_in->setText(set_clock_in.left(2) + "시 " + set_clock_in.right(2) + "분");

        port->write("in_time\n");
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    staff_form = new Dialog_staff_form(this, database_1, ui->tableWidget, port, &staff_count);
    disconnect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));
    staff_form->show();
}

//사원 목록에서 사원 이름을 클릭할 경우,
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString name, phone, card_id;
    QString *staff_info;

    selected_row = row;

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
        database_1->print_dashboard_staff_list(ui->tableWidget_info, card_id);
    }
}

void MainWindow::on_pushButton_del_clicked()
{
    QString card_id = ui->lineEdit_card->text();
    qDebug() << "delete staff : " << card_id << endl;
    if(database_1->del_staff(card_id)){     //성공
        QMessageBox::information(this, "information", "사원정보 삭제 성공");
        ui->lineEdit_name->setText("");
        ui->lineEdit_age->setText("");
        ui->lineEdit_card->setText("");
        ui->lineEdit_phone->setText("");
        ui->tableWidget->removeRow(selected_row);
        database_1->print_staff(ui->tableWidget);
        staff_count -= 1;
    }
        else{       //실패
        QMessageBox::warning(this, "warning", "정보 삭제에 실패했습니다.");
    }
}

//UART통신 함수
void MainWindow::text_Reading(){
    QByteArray read_data;
    QString *staff_info;
    int index;      //데이터 포맷 확인용.
    int state;

    read_data = port->readAll();

    read_string += QString(read_data);

    if(strchr(read_data.data(), '\n')){
        read_string.chop(1);        //마지막 개행문자 제거.
        qDebug() << read_string << endl;

        //출/퇴근 등록에 대한 입력일 경우,
        index = read_string.indexOf("in:");
        if(index != -1){
            read_string.remove(index, 3);
            //입력한 카드로 등록된 사원이 있을 때만 실행.
            if(database_1->count_staff(read_string, 1) != 0){
                //태그한 사원의 상태 조회. 0, 1, 2 --> 신규, 출근, 퇴근 상태 확인
                state = database_1->print_staff_state(read_string);
                database_1->add_clock_in_out(read_string, state, set_clock_in);

                database_1->print_dashboard_list(ui->tableWidget_list);
                //입력된 카드의 사원 정보 출력
                staff_info = database_1->get_staff_info(read_string);
                ui->lineEdit_state_name->setText(staff_info[0]);
                ui->lineEdit_state_card->setText(staff_info[3]);
                //서보모터 동작하도록 전송.
                port->write("servo\n");
            }
            else{
                QMessageBox::warning(this, "warning", "등록된 사원이 아닙니다.");
            }
        }
        read_string = "";
    }
    progress_bar_update();
}

//사원 출/퇴근 확인용 UART연결
void MainWindow::setup_uart(){
    port->setPortName("/dev/ttyACM0");
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    //연결 성공
    if(port->open(QIODevice::ReadWrite)){
        port->write("in_time\n");
    }
    else {
        QMessageBox::information(this, "info", "연결에 실패했습니다.\n");
    }
}

//Progress Bar 업데이트 함수
void MainWindow::progress_bar_update(){
    QSqlQuery query;

    query.exec("select count(*) from staff_list");
    if(query.next()){
        staff_count = query.value(0).toInt();
    }
    ui->progressBar_in->setRange(0, staff_count);
    ui->progressBar_late->setRange(0, staff_count);
    ui->progressBar_normal->setRange(0, staff_count);

    query.exec("select count(*) from attendance_state where status=1");
    if(query.next()){
        staff_count_normal = query.value(0).toInt();
    }
    ui->progressBar_normal->setValue(staff_count_normal);

    query.exec("select count(*) from attendance_state where status=0");
    if(query.next()){
        staff_count_late = query.value(0).toInt();
    }
    ui->progressBar_late->setValue(staff_count_late);
    ui->progressBar_in->setValue(staff_count_late + staff_count_normal);

    qDebug() << "noraml : " << staff_count_normal << " late : " << staff_count_late << " in : " << staff_count;

    ui->label_16->setText(QString::number(staff_count));
}

//메뉴바 설정
void MainWindow::on_action_3_triggered()
{
    clock_form = new Form_set_clock(nullptr, &set_clock_in, ui->label_clock_in);
    clock_form->show();
}

void MainWindow::on_action_triggered()
{
    exit(1);
}
