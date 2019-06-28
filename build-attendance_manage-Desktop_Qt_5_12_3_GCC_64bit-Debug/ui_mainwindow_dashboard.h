/********************************************************************************
** Form generated from reading UI file 'mainwindow_dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_DASHBOARD_H
#define UI_MAINWINDOW_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QLabel *label_time;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_date;
    QLabel *label_6;
    QLineEdit *lineEdit_state_card;
    QLabel *label_7;
    QLineEdit *lineEdit_state_name;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton_add;
    QGroupBox *groupBox_2;
    QTableWidget *tableWidget_info;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_age;
    QLineEdit *lineEdit_phone;
    QLineEdit *lineEdit_card;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_del;
    QLabel *label;
    QLabel *label_8;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1144, 753);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_time = new QLabel(centralWidget);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setGeometry(QRect(920, 5, 221, 71));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label_time->setFont(font);
        label_time->setAlignment(Qt::AlignCenter);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 64, 1121, 641));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_date = new QLabel(tab);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(20, 0, 251, 51));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label_date->setFont(font1);
        label_date->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 73, 67, 17));
        lineEdit_state_card = new QLineEdit(tab);
        lineEdit_state_card->setObjectName(QString::fromUtf8("lineEdit_state_card"));
        lineEdit_state_card->setGeometry(QRect(130, 70, 171, 25));
        lineEdit_state_card->setReadOnly(true);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(87, 114, 41, 17));
        lineEdit_state_name = new QLineEdit(tab);
        lineEdit_state_name->setObjectName(QString::fromUtf8("lineEdit_state_name"));
        lineEdit_state_name->setGeometry(QRect(130, 110, 171, 25));
        lineEdit_state_name->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 281, 581));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 261, 511));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        pushButton_add = new QPushButton(groupBox);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        pushButton_add->setGeometry(QRect(90, 550, 89, 25));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 10, 801, 581));
        tableWidget_info = new QTableWidget(groupBox_2);
        if (tableWidget_info->columnCount() < 3)
            tableWidget_info->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_info->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_info->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_info->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget_info->setObjectName(QString::fromUtf8("tableWidget_info"));
        tableWidget_info->setGeometry(QRect(375, 60, 411, 491));
        tableWidget_info->horizontalHeader()->setMinimumSectionSize(20);
        tableWidget_info->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget_info->horizontalHeader()->setHighlightSections(true);
        tableWidget_info->horizontalHeader()->setStretchLastSection(true);
        lineEdit_name = new QLineEdit(groupBox_2);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(120, 60, 161, 25));
        lineEdit_name->setReadOnly(true);
        lineEdit_age = new QLineEdit(groupBox_2);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(120, 100, 161, 25));
        lineEdit_age->setReadOnly(true);
        lineEdit_phone = new QLineEdit(groupBox_2);
        lineEdit_phone->setObjectName(QString::fromUtf8("lineEdit_phone"));
        lineEdit_phone->setGeometry(QRect(120, 140, 161, 25));
        lineEdit_phone->setReadOnly(true);
        lineEdit_card = new QLineEdit(groupBox_2);
        lineEdit_card->setObjectName(QString::fromUtf8("lineEdit_card"));
        lineEdit_card->setGeometry(QRect(120, 180, 161, 25));
        lineEdit_card->setReadOnly(true);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 61, 41, 21));
        QFont font2;
        font2.setPointSize(13);
        label_2->setFont(font2);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 100, 41, 21));
        label_3->setFont(font2);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 140, 71, 21));
        label_4->setFont(font2);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 180, 71, 21));
        label_5->setFont(font2);
        pushButton_mod = new QPushButton(groupBox_2);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        pushButton_mod->setGeometry(QRect(60, 220, 89, 25));
        pushButton_del = new QPushButton(groupBox_2);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(200, 220, 89, 25));
        tabWidget->addTab(tab_2, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 441, 41));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(410, 40, 341, 17));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1144, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Attendance Management System", nullptr));
        action->setText(QApplication::translate("MainWindow", "\354\204\244\354\240\225", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\354\242\205\353\243\214", nullptr));
        label_time->setText(QApplication::translate("MainWindow", "00 : 00 : 00", nullptr));
        label_date->setText(QApplication::translate("MainWindow", "0000 \353\205\204 00 \354\233\224 00 \354\235\274   \355\231\224\354\232\224\354\235\274", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\354\271\264\353\223\234\353\262\210\355\230\270", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\355\230\204\355\231\251", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\354\202\254\354\233\220 \353\252\251\353\241\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "\354\202\254\354\233\220\354\266\224\352\260\200", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\354\202\254\354\233\220 \354\240\225\353\263\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_info->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\354\266\234\352\267\274 \354\235\274\354\213\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_info->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\355\207\264\352\267\274 \354\235\274\354\213\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_info->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\354\203\201\355\203\234", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\353\202\230\354\235\264", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "RFID KEY", nullptr));
        pushButton_mod->setText(QApplication::translate("MainWindow", "\354\240\225\353\263\264\354\210\230\354\240\225", nullptr));
        pushButton_del->setText(QApplication::translate("MainWindow", "\354\240\225\353\263\264 \354\202\255\354\240\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\354\202\254\354\233\220\352\264\200\353\246\254", nullptr));
        label->setText(QApplication::translate("MainWindow", "(\354\243\274) \352\260\200\353\202\230\353\213\244\353\235\274\353\247\210\353\260\224\354\202\254", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_DASHBOARD_H
