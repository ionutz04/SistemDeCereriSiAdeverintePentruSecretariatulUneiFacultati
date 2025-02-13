#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

class Document {
private:
    std::string title;
    std::string content;

public:
    Document(std::string title, std::string content) : title(title), content(content) {}

    std::string getTitle() const { return title; }
    std::string getContent() const { return content; }

    void printDocument() const {
        std::cout << "Document Title: " << title << "\nContent: " << content << "\n";
    }
};

#endif // DOCUMENT_H
