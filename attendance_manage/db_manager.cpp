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

//태그된 card_id로 출근/퇴근 기록을 데이터베이스에 저장
bool db_manager::add_clock_in_out(QString input_card_id, bool isClock_in){
    QSqlQuery query;
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    QString time_text = date.toString("yyMMdd") + time.toString("hhmm");

    if(isClock_in == true){     //출근시간 기록
        query.prepare("insert into attendance_state(card_id, clock_in) values(:card, :clock_in)");
        query.bindValue(":card", input_card_id);
        query.bindValue(":clock_in", time_text);
        if(query.exec()){
            qDebug() << "Test : " << query.lastQuery().toUtf8() << endl;
        }
        else{
            qDebug() << "Test : " << query.lastError().text() << endl;
            //insert into attendance_state(card_id, clock_in) values('11-11-11-11-11', '시간');
            //query = "insert into attendance_state(card_id, clock_in) values(";
        }
    }
    else if(isClock_in == false){       //퇴근시간 기록
        //update ~~~~~

    }
}

//선택된 사원정보 삭제
bool db_manager::del_staff(QString del_card_id){
    QSqlQuery query;

    if(query.exec("delete from staff_list where card_id='" + del_card_id + "'")){
        qDebug() << query.lastQuery().toUtf8() << endl;
        return true;
    }
    else {
        qDebug() << query.lastError().text() << endl;
        return false;
    }
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
