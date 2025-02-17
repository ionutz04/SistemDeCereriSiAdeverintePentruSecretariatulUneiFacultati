#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include "User.h"
#include "docType.h"
#include <vector>
class Document {
private:
    User* user;
    docType docT;
    std::string status;
public:
    Document(User* user, docType docT): user(user), docT(docT){
        user->loadUserFromDB(user->getId());
    }
    std::vector<std::pair<std::string, std::string>> fillDataForDocType() const;
    std::string insertValues(const std::string& text, const std::vector<std::pair<std::string, std::string>>& valuesMap);
    std::string getName()const{
        return docT.getName();
    }
    std::string getStatus() const { return status; }
    void setStatus(const std::string& newStatus) { status = newStatus; }
    
};

#endif // DOCUMENT_H
