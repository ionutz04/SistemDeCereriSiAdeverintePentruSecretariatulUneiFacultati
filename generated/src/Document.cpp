#ifndef DOCUMENT_CPP
#define DOCUMENT_CPP

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <vector>
#include <sstream>
#include "../include/Document.h"

using std::map;
using std::vector;
using std::string;
using std::cin;
using std::cout;

// Insert values into the text based on provided field data
std::string Document::insertValues(const std::string& text, const std::vector<std::pair<std::string, std::string>>& values) {
    std::istringstream stream(text);
    std::string word;
    std::string result;

    size_t idx = 0;
    while (stream >> word) {
        if (word == "_") {
            if (idx < values.size() && !values[idx].second.empty()) {
                result += values[idx].second + " ";
            } else {
                result += "_ ";
            }
            idx++;
        } else {
            result += word + " ";
        }
    }

    return result;
}

// Helper to get current date in YYYY-MM-DD format
std::string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return std::string(buffer);
}

// Smart field completion logic
std::vector<std::pair<std::string, std::string>> Document::fillDataForDocType() const {
    std::vector<std::pair<std::string, std::string>> fields = docT.getFields();
    std::string subsemnatulName = user->getName() + " " + user->getSurname();

    // Define rules for automated completion
    const std::map<std::string, std::string> autoCompleteRules = {
        {"Subsemnatul", subsemnatulName},
        {"conform situatiei scolare anexate.\nData", getCurrentDate()},
        {"Semnatura", subsemnatulName}
    };

    // Completion logic
    for (auto& [key, value] : fields) {
        // Trim spaces
        while (!key.empty() && key.front() == ' ') key.erase(key.begin());
        while (!key.empty() && key.back() == ' ') key.pop_back();

        // Auto-fill if rule exists
        if (autoCompleteRules.find(key) != autoCompleteRules.end()) {
            value = autoCompleteRules.at(key);
            continue;
        }

        // Check if the key likely refers to a field requiring manual input
        if (key.find("anul") != std::string::npos || 
            key.find("disciplina") != std::string::npos || 
            key.find("nota") != std::string::npos || 
            key.find("Facultatii") != std::string::npos || 
            key.find("grupa") != std::string::npos) {
            cout << "Enter value for " << key << ": ";
            getline(cin, value);
        } else {
            cout << "Unknown key: " << key << " - Please enter value: ";
            getline(cin, value);
        }
    }

    return fields;
}


#endif // DOCUMENT_CPP
