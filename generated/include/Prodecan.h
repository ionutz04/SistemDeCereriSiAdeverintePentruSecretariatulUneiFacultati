


#ifndef PRODECAN_H
#define PRODECAN_H

#include "User.h"
#include "Document.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "PipelineNode.h"
class Prodecan : public User, public PipelineNode {
public:
    Prodecan(int userId) : User(userId) {
        userType = UT::Prodecan;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Prodecan) {
            std::cerr << "Error: User is not a Prodecan!" << std::endl;
            return false;
        }
        return true;
    }

    
    void produce(Document& doc) override {
        std::unique_lock<std::mutex> lock(mtx);
        doc.setStatus("Signed by Secretar");
        buffer.push(doc);
        cv.notify_one();
    }

    void consume() override {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !buffer.empty(); });
        Document doc = buffer.front();
        buffer.pop();
        std::cout << "Secretar processed document: " << doc.getName() << " with status: " << doc.getStatus() << std::endl;
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

#endif // SECRETAR_H