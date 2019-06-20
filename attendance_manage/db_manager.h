#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QDebug>                   //2019.06.19 LJH
#include <QSqlDatabase>     //2019.06.19 LJH
#include <QSqlQuery>           //2019.06.19 LJH
#include <QSqlError>           //2019.06.19 LJH
#include <QMessageBox>  //2019.06.20 LJH
#include <QTableWidget>     //2019.06.21 LJH

class db_manager
{
public:
    db_manager(const QString& path);
    ~db_manager();
    bool add_staff(QString input_name, int input_age, QString input_phone, QString input_card);
    void print_staff(QTableWidget *table);
private:
    QSqlDatabase my_db;
};

#endif // DB_MANAGER_H
