#include "dialog_staff_form.h"
#include "ui_dialog_staff_form.h"

Dialog_staff_form::Dialog_staff_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_staff_form)
{
    ui->setupUi(this);
    //사용자가 card_id는 입력불가.
    ui->lineEdit_card_id->setReadOnly(true);

    //데시보드 변수 생성, 사용 불가 설정.
    dashboard = parent;
    dashboard->setEnabled(false);
    //현재 창 사용가능하도록 설정.
    this->setEnabled(true);
}

Dialog_staff_form::~Dialog_staff_form()
{
    dashboard->setEnabled(true);
    delete ui;
}

//사원정보 등록.
void Dialog_staff_form::on_pushButton_accept_clicked()
{
    QString input_name;
    int input_age = 0;
    QString input_phone;
    QString input_card_id;

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
    dashboard->setEnabled(true);
    this->close();
}

void Dialog_staff_form::on_pushButton_cancel_clicked()
{
    dashboard->setEnabled(true);
    this->close();
}

void Dialog_staff_form::closeEvent(QCloseEvent *event){
    dashboard->setEnabled(true);
    this->close();
}
