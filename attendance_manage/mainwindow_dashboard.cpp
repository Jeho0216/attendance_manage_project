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

    //시리얼 포트 추가 코드 2019.06.26
    port = new QSerialPort();
    setup_uart();
    QObject::connect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));
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

    //------------------------테스트코드 : 삭제
    QString string = date.toString("yyMMdd") + time.toString("hhmm");
    //------------------------테스트코드 끝

    ui->label_date->setText(date_text);
    ui->label_time->setText(time_text);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if(index == 1){
        //port->close();      //사원등록용 port open하기 전에 기존에 open된 port 닫기.
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);        //테이블 수정(edit)불가 설정.
        database_1->print_staff(ui->tableWidget);
    }
    else if(index == 0){

        //setup_uart();       //출/퇴근 체크용 UART PORT연결.
        connect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));      //dashboard text_Reading()
        port->write("in_time\n");
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    staff_form = new Dialog_staff_form(this, database_1, ui->tableWidget, port);
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

    read_data = port->readAll();

    read_string += QString(read_data);

    if(strchr(read_data.data(), '\n')){
        read_string.chop(1);        //마지막 개행문자 제거.

        index = read_string.indexOf("in:");
        if(index != -1){
            read_string.remove(index, 3);
            database_1->add_clock_in_out(read_string, true);
        }

        qDebug() << read_string << " : dashboard\n";
        //입력된 카드의 사원 정보 출력
        staff_info = database_1->get_staff_info(read_string);
        ui->lineEdit_state_name->setText(staff_info[0]);
        ui->lineEdit_state_card->setText(staff_info[3]);
        //사원 출근시간 데이터베이스에 저장. -> 시간 입력시에만 저장되도록 플래그 지정필요.

//        index = read_string.indexOf("in:");
//        if(index != -1){
//            database_1->count_staff(read_string);
//            read_string.remove(index, 3);
//            database_1->add_clock_in_out(read_string, true);
//        }



        read_string = "";
    }
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
