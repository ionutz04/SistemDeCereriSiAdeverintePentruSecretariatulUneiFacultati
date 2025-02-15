#ifndef DECAN_H
#define DECAN_H

#include "User.h"
#include "Document.h"
#include "PipelineNode.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>
#include <random>
#include <iostream>

class Decan : public User, public PipelineNode {
public:
    Decan(int userId) : User(userId) {
        userType = UT::Decan;
    }

    // Load user from DB
    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Decan) {
            std::cerr << "Error: User is not a Decan!" << std::endl;
            return false;
        }
        return true;
    }

    // Produce: Receives a document from the previous node
    void produce(Document& doc) override {
        std::unique_lock<std::mutex> lock(mtx);
        buffer.push(doc);
        cv.notify_one();
    }

    // Consume: Process the document and decide its fate
    void consume() override {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !buffer.empty(); });
        Document doc = buffer.front();
        buffer.pop();

        bool decision = makeDecision();
        if (decision) {
            doc.setStatus("Approved by Decan");
            notifyUser(doc, true);
            if (nextNode) nextNode->produce(doc);
        } else {
            doc.setStatus("Denied by Decan");
            notifyUser(doc, false);
        }
    }

    // Run the consumer thread
    void run() override {
        std::thread([this] {
            while (true) {
                consume();
            }
        }).detach();
    }

    // Set the next node in the pipeline
    void setNext(std::shared_ptr<PipelineNode> next) override {
        nextNode = next;
    }

private:
    std::queue<Document> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    std::shared_ptr<PipelineNode> nextNode;

    // Simulates a decision (approve/deny)
    bool makeDecision() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 1);
        return dist(gen) == 1;
    }

    // Notifies the user of the document's fate
    void notifyUser(const Document& doc, bool approved) {
        std::string status = approved ? "approved" : "denied";
        std::cout << "Notification: Document '" << doc.getName() 
                  << "' was " << status << " by Decan.\n";
    }
};

#endif // DECAN_H
