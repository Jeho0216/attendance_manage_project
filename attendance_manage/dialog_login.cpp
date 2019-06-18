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
        QMessageBox::information(this, "Success", "로그인 성공\n");
        hide();
        main_dashboard = new MainWindow();
        main_dashboard->show();
    }
}
