/********************************************************************************
** Form generated from reading UI file 'dialog_staff_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STAFF_FORM_H
#define UI_DIALOG_STAFF_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_staff_form
{
public:
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_card_id;
    QPushButton *pushButton_accept;
    QLabel *label_5;
    QPushButton *pushButton_rfid_con;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *Dialog_staff_form)
    {
        if (Dialog_staff_form->objectName().isEmpty())
            Dialog_staff_form->setObjectName(QString::fromUtf8("Dialog_staff_form"));
        Dialog_staff_form->resize(336, 359);
        label = new QLabel(Dialog_staff_form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 331, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(Dialog_staff_form);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 70, 301, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEdit_name = new QLineEdit(gridLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMaxLength(20);

        gridLayout->addWidget(lineEdit_name, 1, 1, 1, 1);

        lineEdit_age = new QLineEdit(gridLayoutWidget);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setMaxLength(3);

        gridLayout->addWidget(lineEdit_age, 2, 1, 1, 1);

        lineEdit_phone = new QLineEdit(gridLayoutWidget);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_phone, 4, 1, 1, 1);

        lineEdit_card_id = new QLineEdit(Dialog_staff_form);
        lineEdit_card_id->setObjectName(QString::fromUtf8("lineEdit_card_id"));
        lineEdit_card_id->setGeometry(QRect(20, 250, 301, 31));
        lineEdit_card_id->setAlignment(Qt::AlignCenter);
        pushButton_accept = new QPushButton(Dialog_staff_form);
        pushButton_accept->setObjectName(QString::fromUtf8("pushButton_accept"));
        pushButton_accept->setGeometry(QRect(50, 310, 89, 25));
        label_5 = new QLabel(Dialog_staff_form);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 101, 17));
        pushButton_rfid_con = new QPushButton(Dialog_staff_form);
        pushButton_rfid_con->setObjectName(QString::fromUtf8("pushButton_rfid_con"));
        pushButton_rfid_con->setGeometry(QRect(230, 210, 89, 25));
        pushButton_cancel = new QPushButton(Dialog_staff_form);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 310, 89, 25));

        retranslateUi(Dialog_staff_form);

        QMetaObject::connectSlotsByName(Dialog_staff_form);
    } // setupUi

    void retranslateUi(QDialog *Dialog_staff_form)
    {
        Dialog_staff_form->setWindowTitle(QApplication::translate("Dialog_staff_form", "\354\202\254\354\233\220 \354\240\225\353\263\264", nullptr));
        label->setText(QApplication::translate("Dialog_staff_form", "\354\202\254\354\233\220 \353\223\261\353\241\235 \354\240\225\353\263\264", nullptr));
        label_3->setText(QApplication::translate("Dialog_staff_form", "\353\202\230\354\235\264", nullptr));
        label_2->setText(QApplication::translate("Dialog_staff_form", "\354\235\264\353\246\204", nullptr));
        label_4->setText(QApplication::translate("Dialog_staff_form", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        lineEdit_phone->setInputMask(QApplication::translate("Dialog_staff_form", "999-9999-9999", nullptr));
        lineEdit_phone->setText(QApplication::translate("Dialog_staff_form", "--", nullptr));
        pushButton_accept->setText(QApplication::translate("Dialog_staff_form", "\354\231\204\353\243\214", nullptr));
        label_5->setText(QApplication::translate("Dialog_staff_form", "RFID CARD ID", nullptr));
        pushButton_rfid_con->setText(QApplication::translate("Dialog_staff_form", "RFID \354\227\260\352\262\260", nullptr));
        pushButton_cancel->setText(QApplication::translate("Dialog_staff_form", "\354\267\250\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_staff_form: public Ui_Dialog_staff_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STAFF_FORM_H
