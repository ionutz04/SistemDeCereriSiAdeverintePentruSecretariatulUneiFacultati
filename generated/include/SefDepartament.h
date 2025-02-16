#ifndef SEF_DEPARTAMENT_H
#define SEF_DEPARTAMENT_H

#include "User.h"
#include "Document.h"
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <memory>
#include <random>
#include "PipelineNode.h"
#include <iostream>

class SefDepartament : public User, public PipelineNode {
public:
    SefDepartament(int userId) : User(userId) {
        userType = UT::Sef_Departament;
    }

    bool loadUserFromDB(int userId) override {
        if (!User::loadUserFromDB(userId)) return false;
        if (userType != UT::Sef_Departament) {
            std::cerr << "Error: User is not a SefDepartament!" << std::endl;
            return false;
        }
        return true;
    }

    // Decision-making function
    bool makeDecision() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution dist(0.60);
        return dist(gen);
    }

    // Notify the user of the document's status
    void notifyUser(const Document& doc) {
        std::cout << "Notification: Document '" << doc.getName() 
                  << "' was denied by SefDepartament.\n";
    }

    // Produce: add document to buffer and notify
    void produce(Document& doc) override {
        std::unique_lock<std::mutex> lock(mtx);
        doc.setStatus("Signed by SefDepartament");
        buffer.push(doc);
        cv.notify_one();
    }

    // Consume: process the document
    void consume() override {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return !buffer.empty(); });
        Document doc = buffer.front();
        buffer.pop();

        std::cout << "SefDepartament processed document: " << doc.getName() 
                  << " with status: " << doc.getStatus() << std::endl;

        // Make a decision about the document
        if (makeDecision()) {
            doc.setStatus("Approved by SefDepartament");
            if (nextNode) {
                nextNode->produce(doc);
            }
        } else {
            doc.setStatus("Denied by SefDepartament");
            notifyUser(doc);
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
};

#endif // SEF_DEPARTAMENT_H
