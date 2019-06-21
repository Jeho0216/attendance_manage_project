#include "db_manager.h"

db_manager::db_manager(const QString& path)
{
    my_db = QSqlDatabase::addDatabase("QSQLITE");
    my_db.setDatabaseName(path);

    if(my_db.open()){
        qDebug() << "success DB connection\n";
    }
    else{
        qDebug() << "fail DB connection\n";
    }
}

db_manager::~db_manager(){
    my_db.close();
}

//사원 정보 staff_list에 등록.
bool db_manager::add_staff(QString input_name, int input_age, QString input_phone, QString input_card){
    bool result = false;

    QSqlQuery query;

    query.prepare("insert into staff_list(name, card_id, age, phone) values(:name, :card_id, :age, :phone)");
    query.bindValue(":name", input_name.toUtf8());
    query.bindValue(":card_id", input_card.toUtf8());
    query.bindValue(":age", input_age);
    query.bindValue(":phone", input_phone.toUtf8());

    if(query.exec()){
        qDebug() << query.lastQuery().toUtf8() << endl;
        result = true;
    }
    else{
        qDebug() << query.lastQuery().toUtf8() << endl;
        qDebug() << query.lastError().text();
        result = false;
    }
    return result;
}

//대시보드에 사원 정보 출력
void db_manager::print_staff(QTableWidget *table){
    uint8_t row_count = 0;
    QSqlQuery query;

    query.exec("select name, phone from staff_list");
    while(query.next()){
        QTableWidgetItem *table_name = new QTableWidgetItem();
        QTableWidgetItem *table_phone = new QTableWidgetItem();
        row_count++;
        table->setRowCount(row_count);

        QString name = query.value("name").toString();
        QString phone = query.value("phone").toString();
        table_name->setText(name);
        table_phone->setText(phone);
        qDebug() << "name : " << name << "  phone : " << phone << endl;

        table->setItem(row_count-1, 0, table_name);
        table->setItem(row_count-1, 1, table_phone);
    }
}
