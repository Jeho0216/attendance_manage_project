#include "dialog_login.h"
#include "ui_dialog_login.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->lineEdit_pw->setEchoMode(QLineEdit::Password);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_login_clicked()
{
    QString id = ui->lineEdit_id->text();
    QString pw = ui->lineEdit_pw->text();

    if(id == "admin" && pw == "admin"){
        main_dashboard = new MainWindow();
        main_dashboard->show();
        this->close();
    }
    else{
        ui->label_2->setText("아이디 또는 비밀번호가 잘못되었습니다.");
    }
}

void Dialog::on_pushButton_exit_clicked()
{
    exit(1);
}
