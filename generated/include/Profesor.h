#ifndef PROFESOR_H
#define PROFESOR_H

#include "User.h"
#include "Document.h"
class Profesor : public User {
public:
    Profesor() {
        userType = UT::Profesor;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Profesor) {
            std::cerr << "Error: User is not a Profesor!" << std::endl;
            return false;
        }
        return true;
    }
};

#endif // PROFESOR_H
