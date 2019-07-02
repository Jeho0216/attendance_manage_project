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
bool db_manager::add_clock_in_out(QString input_card_id, int state, QString set_clock_in){
    QSqlQuery query;
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString last_time;      //퇴근시간 입력을 위해 출근시간 확인.
    QString time_text = date.toString("yyMMdd") + time.toString("hhmm");
    bool attendance_state = true;           //true : 정상, false : 지각

    if(time.toString("hhmm").toInt() >= set_clock_in.toInt()){      //태그한 시간이 설정한 시간보다 클 경우,
        attendance_state = false;
    }
    else {
        attendance_state = true;
    }

    if(state == 0 || state == 2){     //출근시간 기록
        qDebug() << "출근 등록\n";
        query.prepare("insert into attendance_state(card_id, clock_in, status) values(:card, :time_in, :status)");       //사원의 출입시간 등록
        query.bindValue(":card", input_card_id);
        query.bindValue(":time_in", time_text);
        query.bindValue(":status", attendance_state);

        if(query.exec()){
            qDebug() << query.lastQuery() << endl;
            if(query.exec("update staff_list set state=1 where card_id='" + input_card_id + "'")){      //사원의 상태(state)변경
                qDebug() << query.lastQuery() << endl;
            }
            else {
                qDebug() << query.lastError();
            }
            query.exec("update staff_list set last_clock_in='" + time_text + "' where card_id='" + input_card_id + "'");
            return true;
        }
        else{
            qDebug() << query.lastError().text() << endl;
            return false;
        }
    }
    else if(state == 1){       //퇴근시간 기록
        qDebug() << "퇴근 등록\n";
        query.exec("select last_clock_in from staff_list where card_id='" + input_card_id + "'");
        if(query.next()){
            last_time = query.value("last_clock_in").toString();                                                                            //입력된 사원의 최근 출입시간 저장.
        }
        if(query.exec("update staff_list set state=2 where card_id='" + input_card_id + "'")){               //사원의 상태 변경 -> 퇴근
            qDebug() << query.lastQuery() << endl;
        }
        else {
            qDebug() << query.lastError().text() << endl;
        }
        //출근시간, 사원번호가 일치하는 사원의 퇴근시간 추가.
        if(query.exec("update attendance_state set clock_out='" + time_text + "' where clock_in='" + last_time + "' AND card_id='" + input_card_id + "'")){
            qDebug() << query.lastQuery() << endl;
        }
        else {
            qDebug() << query.lastError().text() << endl;
        }
        query.exec("update staff_list set last_clock_in='" + time_text + "' where card_id='" + input_card_id + "'");
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

//출/퇴근 시, 카드에 해당하는 사원의 상태 확인. 0: 신규, 1: 출근, 2: 퇴근
int db_manager::print_staff_state(QString input_card_id){
    QSqlQuery query;
    int staff_state = 0;

    query.exec("select state from staff_list where card_id='" + input_card_id + "'");
    while(query.next()){
        query.first();
        staff_state = query.value("state").toInt();
    }
    qDebug() << "card_id : " << input_card_id << staff_state << endl;

    return staff_state;
}

//카드에 해당하는 사원 찾기
int db_manager::count_staff(QString input_card_id){
    QSqlQuery query;
    int rows = 0;

    query.exec("select count(*) from staff_list where card_id='" + input_card_id + "'");
    if(query.next()){       //Query.next() 이후에 count값 저장해야 정상적으로 값 저장됨.
        rows = query.value(0).toInt();
    }
    qDebug() << input_card_id << " number : " << QString::number(rows) << endl;
    return rows;
}

//대시보드의 현황 탭에 출/퇴근 현황 테이블  출력.
void db_manager::print_dashboard_list(QTableWidget *table){
    uint8_t row_count = 0;
    QSqlQuery query;
    QString query_str;
    qDebug() << "start print dashbord" << endl;

    query_str = "select staff_list.name, attendance_state.clock_in, attendance_state.clock_out, attendance_state.status from staff_list join attendance_state where staff_list.card_id=attendance_state.card_id";

    if(query.exec(query_str)){
        qDebug() << query.lastQuery() << endl;
        while(query.next()){
            QTableWidgetItem *table_name = new QTableWidgetItem();
            QTableWidgetItem *table_clock_in = new QTableWidgetItem();
            QTableWidgetItem *table_clock_out = new QTableWidgetItem();
            QTableWidgetItem *table_status = new QTableWidgetItem();        //출/퇴근 상태 표현용
            row_count++;
            table->setRowCount(row_count);

            QString name = query.value("name").toString();
            QString clock_in = query.value("clock_in").toString();
            QString clock_out = query.value("clock_out").toString();
            QString status = query.value("status").toString();        //출/퇴근 상태 표현용
            if(status == "0")   status = "지각";
           else                            status = "정상";
            table_name->setText(name);
            table_clock_in->setText(clock_in);
            table_clock_out->setText(clock_out);
            table_status->setText(status);        //출/퇴근 상태 표현용

            qDebug() << "name : " << name << "  clock_in : " << clock_in << "  clock_out : " << clock_out << endl;

            table->setItem(row_count-1, 0, table_name);
            table->setItem(row_count-1, 1, table_clock_in);
            table->setItem(row_count-1, 2, table_clock_out);
            table->setItem(row_count-1, 3, table_status);
        }
    }
    else{
        qDebug() << query.lastError().text() << endl;
    }
}

//대시보드의 사원관리 탭에 사원별 출/퇴근 시간 출력.
void db_manager::print_dashboard_staff_list(QTableWidget *table, QString input_card_id){
    QSqlQuery query;
    uint8_t row_count = 0;

    if(query.exec("select * from attendance_state where card_id='" + input_card_id + "'")){
        qDebug() << query.lastQuery() << endl;
        while(query.next()){
            QTableWidgetItem *table_clock_in = new QTableWidgetItem();
            QTableWidgetItem *table_clock_out = new QTableWidgetItem();
            row_count++;
            table->setRowCount(row_count);

            QString clock_in = query.value("clock_in").toString();
            QString clock_out = query.value("clock_out").toString();
            table_clock_in->setText(clock_in);
            table_clock_out->setText(clock_out);

            table->setItem(row_count-1, 0, table_clock_in);
            table->setItem(row_count-1, 1, table_clock_out);
        }
    }
    else {
        qDebug() << query.lastError().text() << endl;
    }

}

//사원의 이름으로 card_id 조회
QString db_manager::get_card_id(QString name, QString phone){
    QSqlQuery query;
    QString query_str = "select card_id from staff_list where name='" + name + "'and phone='" + phone + "'";
    qDebug() << query_str << endl;

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
    qDebug() << query.lastQuery() << endl;
    query.first();
    staff_info[0] = query.value("name").toString();
    staff_info[1] = query.value("age").toString();
    staff_info[2] = query.value("phone").toString();
    staff_info[3] = query.value("card_id").toString();

    return staff_info;
}
