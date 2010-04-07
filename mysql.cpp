#include "mysql.h"

/**
* Default Constructor
*/

Mysql::Mysql()
{

}


string Mysql::getResult()
{
    return this->m_result;
}


void Mysql::setQuery(string sql)
{
    this->sqlquery = sql;
}


void Mysql::query()
{
    string output = "";

    mysql_init(&this->mysql);
    this->connection = mysql_real_connect(&this->mysql,"localhost","CS4313_G5","ghbn56","elearning",0,0,0);
    if (this->connection == NULL)
    {
        output = output + mysql_error(&this->mysql) + "\n";
    }
    else
    {
        this->query_state = mysql_query(this->connection, this->sqlquery.c_str() );

        if (this->query_state !=0)
        {
            output = output + mysql_error(this->connection) + "\n";
        }
        else
        {
            this->result = mysql_store_result(this->connection);
            while ( ( this->row = mysql_fetch_row(this->result)) != NULL )
            {
                output = output + this->row[0] + "\n";
            }
            mysql_free_result(this->result);
            mysql_close(this->connection);
        }
    }

    this->m_result = output;
}
