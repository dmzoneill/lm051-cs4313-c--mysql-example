#ifndef MYSQL_H_
#define MYSQL_H_

#include <string>
#include <iostream>
#include <mysql/mysql.h>

using namespace std;


class Mysql
{
    private:
        MYSQL *connection, mysql;
        MYSQL_RES *result;
        MYSQL_ROW row;
        int query_state;
        string m_result;
        string sqlquery; // "select * from serial where id<100"


    public:
        Mysql();
        string getResult();
        void setQuery(string sql);
        void query();

};


#endif /*MYSQL_H_*/
