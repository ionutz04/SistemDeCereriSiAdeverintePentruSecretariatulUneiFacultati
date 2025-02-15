#ifndef DOCUMENT_CPP
#define DOCUMENT_CPP

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include "../include/Document.h"
using std::map;
using std::string;
using std::cin;
using std::cout;

std::string Document::insertValues(const std::string& text, const std::map<std::string, std::string>& valuesMap) {
    std::istringstream stream(text);
    std::string word;
    std::string result;
    std::string lastKey;
    bool expectValue = false;

    while (stream >> word) {
        if (expectValue && word == "_") {
            if (valuesMap.find(lastKey) != valuesMap.end()) {
                result += valuesMap.at(lastKey) + " ";
            } else {
                result += "_ ";
            }
            expectValue = false;
        } else {
            result += word + " ";
            if (valuesMap.find(word) != valuesMap.end()) {
                lastKey = word;
                expectValue = true;
            }
        }
    }

    return result;
}

map<string,string> Document::fillDataForDocType() const {
    map<string,string> fields = docT.getFields();

    string subsemnatulName;
    for (auto &[key, value] : fields) {
        if (key == "Subsemnatul") {
            std::cout << " | " << user->getName() + " " + user->getSurname() << " | " << std::endl;
            value = user->getName() + " " + user->getSurname();
            subsemnatulName = value;
            if (value.empty()) {
                cout << "Enter value for " << key << ": ";
                getline(cin, value);
                subsemnatulName = value;
            }
        } else if (key == "Facultatii" || key == "anul" || key == "disciplina" || key == "disciplinei" ||
                   key == "finantare" || key == "grupa" || key == "invatamant" || key == "nota" ||
                   key == "semestrul" || key == "univ." || key == "universitare") {
            cout << "Enter value for " << key << ": ";
            getline(cin, value);
        } else if (key == "Data") {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            value = std::to_string(1900 + ltm->tm_year) + "-" +
                    std::to_string(1 + ltm->tm_mon) + "-" +
                    std::to_string(ltm->tm_mday);
        } else if (key == "Semnatura") {
            value = subsemnatulName;
        } else {
            cout << "Unknown key: " << key << "\n";
        }
    }
    return fields;
}

#endif // DOCUMENT_CPP
