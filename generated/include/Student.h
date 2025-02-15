#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Document.h"
#include "docType.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>
#include "PipelineNode.h"
class Student : public User, public PipelineNode{
public:
Student(int userId) : User(userId) {
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

void produce(Document& doc) override {
    std::unique_lock<std::mutex> lock(mtx);
    doc.setStatus("Created by Student");
    buffer.push(doc);
    cv.notify_one();
}

void consume() override {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !buffer.empty(); });
    Document doc = buffer.front();
    buffer.pop();
    std::cout << "Student processed document: " << doc.getName() << " with status: " << doc.getStatus() << std::endl;
    if (nextNode) {
        nextNode->produce(doc);
    }
}

void run() override {
    std::thread([this] {
        while (true) {
            consume();
        }
    }).detach();
}

void setNext(std::shared_ptr<PipelineNode> next) override {
    nextNode = next;
}

private:
std::queue<Document> buffer;
std::mutex mtx;
std::condition_variable cv;
std::shared_ptr<PipelineNode> nextNode;
};

#endif // STUDENT_H