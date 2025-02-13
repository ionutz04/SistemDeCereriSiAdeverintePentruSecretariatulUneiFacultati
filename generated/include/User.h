#ifndef OOP_USER_H
#define OOP_USER_H

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

using ::std::string;

// Enum for user roles
enum class UT {
    Decan,
    Prodecan,
    Secretar_sef,
    Sef_Departament,
    Secretar,
    Student,
    Profesor,
    UNKNOWN
};

class User {
protected:
    int id;
    string name, surname, username, passwd;
    std::chrono::system_clock::time_point date_create;  //  Store DATETIME as `time_point`
    UT userType;

public:
    User() : id(0), userType(UT::UNKNOWN) {}
    virtual ~User() = default;

    virtual bool loadUserFromDB(int id);

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getUsername() const { return username; }
    string getDateCreate() const;
    UT getUserType() const { return userType; }
};

#endif // OOP_USER_H
