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
void Connection::executeQuery(const string &query){
    if(mysql_query(conn, query.c_str())){
        throw std::runtime_error(string("Querry failed: ") + mysql_error(conn));
    }
    res = mysql_store_result(conn);
    if(res){
        int num_filds = mysql_num_fields(res);
        while((row = mysql_fetch_field(res))){
            for(int i = 0; i < num_filds; i++){
                cout << (row[i]? row[i] : "NULL") << " ";
            }
            cout << std::endl;
        }
    }else{
            cout << "Querry excuted successfully"<<std::endl;
    }
    mysql_free_result(res);
}

void Connection::close(){
    if(conn){
        mysql_close(conn);
        conn = nullptr;
        cout << "MySQL connection closed!" << std::endl;
    }
}
