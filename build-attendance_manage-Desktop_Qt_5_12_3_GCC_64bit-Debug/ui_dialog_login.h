/********************************************************************************
** Form generated from reading UI file 'dialog_login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_LOGIN_H
#define UI_DIALOG_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_login;
    QPushButton *pushButton_exit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_pw;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(389, 321);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 220, 361, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_login = new QPushButton(verticalLayoutWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        verticalLayout->addWidget(pushButton_login);

        pushButton_exit = new QPushButton(verticalLayoutWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 371, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Light"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 102, 21, 21));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 142, 67, 17));
        lineEdit_id = new QLineEdit(Dialog);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(110, 100, 201, 25));
        lineEdit_pw = new QLineEdit(Dialog);
        lineEdit_pw->setObjectName(QString::fromUtf8("lineEdit_pw"));
        lineEdit_pw->setGeometry(QRect(110, 140, 201, 25));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Attendance Management System", nullptr));
        pushButton_login->setText(QApplication::translate("Dialog", "Login", nullptr));
        pushButton_exit->setText(QApplication::translate("Dialog", "EXIT", nullptr));
        label->setText(QApplication::translate("Dialog", "Attendance Manage System", nullptr));
        label_2->setText(QApplication::translate("Dialog", "ID", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LOGIN_H
