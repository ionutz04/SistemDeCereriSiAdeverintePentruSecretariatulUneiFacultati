#ifndef DECAN_H
#define DECAN_H

#include "User.h"
#include "Document.h"
class Decan : public User {
public:
    Decan() {
        userType = UT::Decan;  // Set the correct user type
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Decan) {
            std::cerr << "Error: User is not a Decan!" << std::endl;
            return false;
        }
        return true;
    }

    void vizare(Document& doc) {
        std::cout << "Decan " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }

    void aprobare(Document& doc) {
        std::cout << "Decan " << name << " is approving document: " << doc.getTitle() << std::endl;
    }
};

#endif // DECAN_H
