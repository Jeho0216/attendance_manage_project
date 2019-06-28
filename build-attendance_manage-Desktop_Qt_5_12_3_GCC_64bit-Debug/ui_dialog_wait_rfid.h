/********************************************************************************
** Form generated from reading UI file 'dialog_wait_rfid.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_WAIT_RFID_H
#define UI_DIALOG_WAIT_RFID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_wait_rfid
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *Dialog_wait_rfid)
    {
        if (Dialog_wait_rfid->objectName().isEmpty())
            Dialog_wait_rfid->setObjectName(QString::fromUtf8("Dialog_wait_rfid"));
        Dialog_wait_rfid->resize(366, 121);
        pushButton = new QPushButton(Dialog_wait_rfid);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 80, 89, 25));
        label = new QLabel(Dialog_wait_rfid);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 351, 31));
        QFont font;
        font.setPointSize(13);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Dialog_wait_rfid);

        QMetaObject::connectSlotsByName(Dialog_wait_rfid);
    } // setupUi

    void retranslateUi(QDialog *Dialog_wait_rfid)
    {
        Dialog_wait_rfid->setWindowTitle(QApplication::translate("Dialog_wait_rfid", "Tag RFID", nullptr));
        pushButton->setText(QApplication::translate("Dialog_wait_rfid", "\354\267\250\354\206\214", nullptr));
        label->setText(QApplication::translate("Dialog_wait_rfid", "\354\202\254\354\232\251\354\236\220\354\235\230 RFID \354\271\264\353\223\234\353\245\274 \355\203\234\352\267\270 \355\225\264\354\243\274\354\204\270\354\232\224.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_wait_rfid: public Ui_Dialog_wait_rfid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_WAIT_RFID_H
