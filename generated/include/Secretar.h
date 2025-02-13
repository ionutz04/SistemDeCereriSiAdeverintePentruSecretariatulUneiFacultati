#ifndef SECRETAR_H
#define SECRETAR_H

#include "User.h"
#include "Document.h"

class Secretar : public User {
public:
    Secretar() {
        userType = UT::Secretar;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Secretar) {
            std::cerr << "Error: User is not a Secretar!" << std::endl;
            return false;
        }
        return true;
    }

    void inregistrare(Document& doc) {
        std::cout << "Secretar " << name << " is registering document: " << doc.getTitle() << std::endl;
    }

    void repartizare(Document& doc) {
        std::cout << "Secretar " << name << " is distributing document: " << doc.getTitle() << std::endl;
    }

    void vizare(Document& doc) {
        std::cout << "Secretar " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }
};

#endif // SECRETAR_H
