
#ifndef SECRETAR_SEF_H
#define SECRETAR_SEF_H

#include "User.h"
#include "Document.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "PipelineNode.h"
class SecretarSef : public User, public PipelineNode {
public:
    SecretarSef(int userId) : User(userId) {
        userType = UT::Secretar_sef;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Secretar_sef) {
            std::cerr << "Error: User is not a Secretar Sef!" << std::endl;
            return false;
        }
        return true;
    }

    
    void produce(Document& doc) override {
        std::unique_lock<std::mutex> lock(mtx);
        doc.setStatus("Signed by Secretar_Sef");
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