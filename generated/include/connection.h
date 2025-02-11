#ifndef OOP_CONNECTION_H
#define OOP_CONNECTION_H
//#include <mysqlx/xdevapi.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include <stdexcept>
using ::std::cin;
using ::std::cout;
using ::std::string;
class Connection{
private:
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
public:
    Connection();
    bool connect(const string &host, const string &user, const string &passwd, const string &database, const int port);
    void close();
    void executeQuery(const std::string &query);
    ~Connection(){
        close();
    };
};

#endif //OOP_CONNECTION_H