#include "../include/connection.h"
#include <iostream>
#include <string>
#include <stdexcept>
using ::std::cin;
using ::std::cout;

Connection::Connection(std::string ip, std::string username, std::string password, std::string databaseName, int port, std::string unixSocket, unsigned long clientFlag){
    this->ip = ip;
    this->username = username;
    this->password = password;
    this->databaseName = databaseName;
    this->port = port;
    this->unixSocket = unixSocket;
    this->clientFlag = clientFlag;
}
Connection::~Connection() {
    close();
}
void Connection::connect(){
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (conn == NULL){
        throw std::runtime_error("MySQL initialization failed: " + std::string(mysql_error(NULL)));
    }
    if (mysql_real_connect(conn, ip.c_str(), username.c_str(), password.c_str(), databaseName.c_str(), port, unixSocket.empty() ? NULL : unixSocket.c_str(), clientFlag) == NULL){
        throw std::runtime_error("MySQL connection failed: " + std::string(mysql_error(conn)));
    }
    cout << "Connected to MySQL server successfully\n";
    mysql_close(conn);
}
void Connection::close(){
    mysql_close(conn);
}