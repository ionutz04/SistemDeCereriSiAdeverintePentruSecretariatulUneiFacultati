#ifndef PRODECAN_H
#define PRODECAN_H

#include "User.h"
#include "Document.h"
class Prodecan : public User {
public:
    Prodecan() {
        userType = UT::Prodecan;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Prodecan) {
            std::cerr << "Error: User is not a Prodecan!" << std::endl;
            return false;
        }
        return true;
    }void repartizare(Document& doc) {
        std::cout << "Prodecan " << name << " is distributing document: " << doc.getTitle() << std::endl;
    }

    void vizare(Document& doc) {
        std::cout << "Prodecan " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }

    void aprobare(Document& doc) {
        std::cout << "Prodecan " << name << " is approving document: " << doc.getTitle() << std::endl;
    }
};

#endif // PRODECAN_H
