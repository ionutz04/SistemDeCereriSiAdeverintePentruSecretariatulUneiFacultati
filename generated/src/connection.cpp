#include "../include/connection.h"
#include <iostream>
#include <string>
#include <stdexcept>
using ::std::cin;
using ::std::cout;
using ::std::string;
Connection::Connection(){
    conn = mysql_init(nullptr);
    if(!conn){
        throw std::runtime_error("Mysql Initialization Failed!");
    }
}

bool Connection::connect(const string &host, const string &user, const string &passwd, const string &database, const int port){
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), port, NULL, 0);
    if(!conn){
        throw std::runtime_error(std::string("Connection Faild: ") + mysql_error(conn));
    }
    cout << "Connected to MySQL successfuly!" << std::endl;
    return true;
}
MYSQL_RES* Connection::getResult(){
    if(!res){
        throw std::runtime_error("No result available. Did you execute the querry?");
    }
    return res;
}
void Connection::executeQuery(const std::string &query) {
    if (!conn) {
        throw std::runtime_error("executeQuery() failed: MySQL connection is not initialized.");
    }

    std::cout << "Executing query: " << query << std::endl;

    if (mysql_query(conn, query.c_str())) {
        throw std::runtime_error(std::string("Query execution failed: ") + mysql_error(conn));
    }

    res = mysql_store_result(conn);
    if (!res && mysql_errno(conn)) {
        throw std::runtime_error(std::string("mysql_store_result() failed: ") + mysql_error(conn));
    }
}


void Connection::close(){
    if(conn){
        mysql_close(conn);
        conn = nullptr;
        cout << "MySQL connection closed!" << std::endl;
    }
}
