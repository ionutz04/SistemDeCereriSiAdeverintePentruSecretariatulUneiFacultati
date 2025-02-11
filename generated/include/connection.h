#ifndef OOP_HELPER_H
#define OOP_HELPER_H
//#include <mysqlx/xdevapi.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include <stdexcept>
using ::std::cin;
using ::std::cout;

class Connection{
private:
    MYSQL* conn;
    std::string ip;
    std::string username;
    std::string password;
    std::string databaseName; 
    int port;
    std::string unixSocket;
    unsigned long clientFlag;
public:
    Connection(std::string ip, std::string username, std::string password, std::string databaseName, int port, std::string unixSocket, unsigned long clientFlag){
    };
    void connect(){};
    void close(){};
    ~Connection(){};
};

#endif //OOP_HELPER_H
