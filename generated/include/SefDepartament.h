#ifndef SEFDEPARTAMENT_H
#define SEFDEPARTAMENT_H

#include "User.h"
#include "Document.h"
class SefDepartament : public User {
public:
    SefDepartament() {
        userType = UT::Sef_Departament;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Sef_Departament) {
            std::cerr << "Error: User is not a Sef Departament!" << std::endl;
            return false;
        }
        return true;
    }

    void vizare(Document& doc) {
        std::cout << "Sef Departament " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }

    void aprobare(Document& doc) {
        std::cout << "Sef Departament " << name << " is approving document: " << doc.getTitle() << std::endl;
    }
};

#endif // SEFDEPARTAMENT_H
