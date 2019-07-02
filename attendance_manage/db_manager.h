#ifndef DB_MANAGER_H
#define DB_MANAGER_H

#include <QDebug>                   //2019.06.19 LJH
#include <QSqlDatabase>     //2019.06.19 LJH
#include <QSqlQuery>           //2019.06.19 LJH
#include <QSqlError>           //2019.06.19 LJH
#include <QMessageBox>  //2019.06.20 LJH
#include <QTableWidget>     //2019.06.21 LJH
#include <QTime>        //2019.06.27 LJH
#include <QDate>        //2019.06.27 LJH

class db_manager
{
public:
    db_manager(const QString& path);
    ~db_manager();
    bool add_staff(QString input_name, int input_age, QString input_phone, QString input_card);
    bool del_staff(QString del_card_id);
    bool add_clock_in_out(QString input_card_id, int state, QString set_clock_in);
    void print_staff(QTableWidget *table);
    int print_staff_state(QString input_card_id);
    int count_staff(QString input_card_id);
    void print_dashboard_list(QTableWidget *table);             //대시보드의 현황 탭에 출/퇴근 현황 테이블  출력.
    void print_dashboard_staff_list(QTableWidget *table, QString input_card_id);        //대시보드의 사원관리 탭에 사원별 출/퇴근 현황 테이블 출력.
    QString get_card_id(QString name, QString phone);       //이름과 전화번호로 card_id 검색
    QString *get_staff_info(QString search_card_id);
    void insert_time_string(QString *time_str);         //0000000000로 입력되는 시간 문자열에 년, 월, 일, 시, 분 문자 추가하는 함수.
private:
    QSqlDatabase my_db;
    QString card_id;          //조회한 사원 card_id
    QString staff_info[4];  //조회한 사원 정보 저장. 이름, 나이, 전화번호, card id
};

#endif // DB_MANAGER_H
