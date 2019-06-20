#include "dialog_staff_form.h"
#include "ui_dialog_staff_form.h"

Dialog_staff_form::Dialog_staff_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_staff_form)
{
    ui->setupUi(this);

    //사용자가 card_id는 입력불가.
    ui->lineEdit_card_id->setReadOnly(true);

    //DB 연결
    database_1 = new db_manager("attendance_mng");        //DB 생성자로 연결가능.

    //RFID 태그 연결
    port = new QSerialPort();
    setup_uart();
    QObject::connect(port, SIGNAL(readyRead()), this, SLOT(text_Reading()));
    port->write("rfid\n");
    qDebug() << "rfid\n";

    //대시보드 변수 생성, 사용 불가 설정.
    dashboard = parent;
    dashboard->setEnabled(false);

    //현재 창 사용가능하도록 설정.
    this->setEnabled(true);
}

Dialog_staff_form::~Dialog_staff_form()
{
    delete ui;
}

//UART통신 함수
void Dialog_staff_form::text_Reading(){
    QByteArray read_data;

    read_data = port->readAll();

    read_string += QString(read_data);

    if(strchr(read_data.data(), '\n')){
        read_string.chop(1);        //마지막 개행문자 제거.
        qDebug() << read_string ;
        ui->lineEdit_card_id->setText(read_string);     //card id 칸에 출력
        read_string = "";
    }
}

//사원정보 등록.
void Dialog_staff_form::on_pushButton_accept_clicked()
{
    QString input_name;
    int input_age = 0;
    QString input_phone;
    QString input_card_id;
    bool result = false;

    input_name = ui->lineEdit_name->text();
    input_age = ui->lineEdit_age->text().toInt();
    input_phone = ui->lineEdit_phone->text();
    input_card_id = ui->lineEdit_card_id->text();

    if(input_name == ""){
        QMessageBox::warning(this, "warning", "이름을 입력하세요.");
        return;
    }
    if(input_age == 0){
        QMessageBox::warning(this, "warning", "나이를 입력하세요.");
        return;
    }
    if(input_phone == ""){
        QMessageBox::warning(this, "warning", "전화번호를 입력하세요.");
        return;
    }
    if(input_card_id == ""){
        QMessageBox::warning(this, "warning", "RFID카드를 등록하세요.");
        return;
    }
    //전부 입력되었을 경우,
    //데이터베이스에 추가하는 코드 필요.
    result = database_1->add_staff(input_name, input_age, input_phone, input_card_id);

    if(result == true){
        dashboard->setEnabled(true);

        delete database_1;
        port->close();
        this->close();
    }
    else{
        QMessageBox::warning(this, "Inser Error", "중복된 RFID카드 입니다.");
        port->write("rfid\n");
        return ;
    }
}

void Dialog_staff_form::on_pushButton_cancel_clicked()
{
    dashboard->setEnabled(true);
    port->close();
    this->close();
}

void Dialog_staff_form::closeEvent(QCloseEvent *event){
    dashboard->setEnabled(true);
    port->write("rfid_cancel\n");
    port->close();
    this->close();
}

//RFID 카드 값을 읽어오기 위한 UART 셋업. 끝나면 close 해줘야 한다.
void Dialog_staff_form::setup_uart(){
    port->setPortName("/dev/ttyACM0");
    port->setBaudRate(QSerialPort::Baud115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::NoFlowControl);
    //연결 성공
    if(port->open(QIODevice::ReadWrite)){
        qDebug() << "RFID 연결 성공\n";
        ui->pushButton_rfid_con->setDisabled(true);
    }
    else {
        QMessageBox::information(this, "info", "RFID 장치와 연결에 실패했습니다.\n");
    }
}

//RFID 재 연결을 위한 함수.
void Dialog_staff_form::on_pushButton_rfid_con_clicked()
{
    setup_uart();
}
