#include "Queue.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (front != nullptr) {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

void Queue::enqueue(const Patient& p) {
    QueueNode* newNode = new QueueNode{ p, nullptr };

    if (front == nullptr) {
        front = rear = newNode;
        return;
    }

    if (p.isUrgent) {
        if (!front->patient.isUrgent) {
            newNode->next = front;
            front = newNode;
            return;
        }

        QueueNode* current = front;
        while (current->next != nullptr && current->next->patient.isUrgent) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) {
            rear = newNode;
        }
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool Queue::dequeue(Patient& outPatient) {
    if (front == nullptr) {
        return false;
    }

    QueueNode* temp = front;
    outPatient = temp->patient;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return true;
}

void Queue::displayQueue() const {
    if (front == nullptr) {
        std::cout << "\nWaiting queue is empty.\n";
        return;
    }

    std::cout << "\n--- Waiting Queue ---\n";
    int index = 1;
    QueueNode* current = front;
    while (current != nullptr) {
        std::cout << index++ << ". ID: " << current->patient.id
            << " | Name: " << current->patient.name
            << " | Priority: " << (current->patient.isUrgent ? "Urgent" : "Normal")
            << " | Condition: " << current->patient.condition << "\n";
        current = current->next;
    }
}

bool Queue::isEmpty() const {
    return front == nullptr;
}