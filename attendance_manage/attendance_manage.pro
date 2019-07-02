#-------------------------------------------------
#
# Project created by QtCreator 2019-06-18T11:27:15
#
#-------------------------------------------------

QT       += core gui
QT += serialport
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = attendance_manage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        db_manager.cpp \
        dialog_login.cpp \
        dialog_staff_form.cpp \
        form_set_clock.cpp \
        main.cpp \
        mainwindow_dashboard.cpp

HEADERS += \
        db_manager.h \
        dialog_login.h \
        dialog_staff_form.h \
        form_set_clock.h \
        mainwindow_dashboard.h

FORMS += \
        dialog_login.ui \
        dialog_staff_form.ui \
        form_set_clock.ui \
        mainwindow_dashboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ui_image.qrc
