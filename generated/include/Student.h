#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Document.h"
class Student : public User {
public:
    Student() {
        userType = UT::Student;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Student) {
            std::cerr << "Error: User is not a Student!" << std::endl;
            return false;
        }
        return true;
    }
    void intocmire(Document& doc) {
        std::cout << "Student " << name << " is drafting document: " << doc.getTitle() << std::endl;
    }

    void vizare(Document& doc) {
        std::cout << "Student " << name << " is verifying document: " << doc.getTitle() << std::endl;
    }
};

#endif // STUDENT_H//TODO remake the atributions for the student;
