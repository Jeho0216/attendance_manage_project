#include "form_set_clock.h"
#include "ui_form_set_clock.h"

Form_set_clock::Form_set_clock(QWidget *parent, QString *input_set_clock, QLabel *input_label) :
    QWidget(parent),
    ui(new Ui::Form_set_clock)
{
    ui->setupUi(this);
    set_clock = input_set_clock;
    label = input_label;
}

Form_set_clock::~Form_set_clock()
{
    delete ui;
}

void Form_set_clock::on_pushButton_set_clicked()
{
    QString set_clock_time;
    QString temp = "%1";

    set_clock_time = temp.arg(ui->spinBox_hh->value(), 2, 10, QChar('0'));
    set_clock_time += temp.arg(ui->spinBox_mm->value(), 2, 10, QChar('0'));

    *set_clock = set_clock_time;
    label->setText(set_clock_time.left(2) + "시 " + set_clock_time.right(2) + "분");
    this->close();
}

void Form_set_clock::on_pushButton_cancel_clicked()
{
    this->close();
}
