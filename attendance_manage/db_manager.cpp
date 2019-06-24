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
    query.bindValue(":name", input_name);
    query.bindValue(":card_id", input_card);
    query.bindValue(":age", input_age);
    query.bindValue(":phone", input_phone);

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

//사원의 이름으로 card_id 조회
QString db_manager::get_card_id(QString name, QString phone){
    QSqlQuery query;
    QString query_str = "select card_id from staff_list where name='" + name + "'and phone='" + phone + "'";
    qDebug() << query_str << endl;
    int i = 0;

    query.exec(query_str);

    while(query.next()){
        query.first();
        card_id = query.value("card_id").toString();
        qDebug() << "name : " << name << "  card id : " << card_id << endl;
    }
    return card_id;
}

//card id로 사원정보 출력
QString *db_manager::get_staff_info(QString search_card_id){

    QSqlQuery query;

    query.exec("select * from staff_list where card_id='" + search_card_id + "'");
    query.first();

    staff_info[0] = query.value("name").toString();
    staff_info[1] = query.value("age").toString();
    staff_info[2] = query.value("phone").toString();
    staff_info[3] = query.value("card_id").toString();

    return staff_info;
}
