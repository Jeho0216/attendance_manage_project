#ifndef FORM_SET_CLOCK_H
#define FORM_SET_CLOCK_H

#include <QWidget>
#include <QDebug>
#include <QLabel>

namespace Ui {
class Form_set_clock;
}

class Form_set_clock : public QWidget
{
    Q_OBJECT

public:
    explicit Form_set_clock(QWidget *parent, QString *input_set_clock, QLabel *input_label);
    ~Form_set_clock();

private slots:
    void on_pushButton_set_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::Form_set_clock *ui;
    QString *set_clock;
    QLabel *label;
};

#endif // FORM_SET_CLOCK_H
