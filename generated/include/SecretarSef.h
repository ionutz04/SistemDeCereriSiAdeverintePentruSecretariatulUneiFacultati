#ifndef SECRETARSEF_H
#define SECRETARSEF_H

#include "User.h"
#include "Document.h"
class SecretarSef : public User {
public:
    SecretarSef() {
        userType = UT::Secretar_sef;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Secretar_sef) {
            std::cerr << "Error: User is not a Secretar Sef!" << std::endl;
            return false;
        }
        return true;
    }
    void repartizare(Document& doc) {
        std::cout << "Secretar Sef " << name << " is distributing document: " << doc.getTitle() << std::endl;
    }

    void vizare(Document& doc) {
        std::cout << "Secretar Sef " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }
};

#endif // SECRETARSEF_H
