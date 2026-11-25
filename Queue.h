#ifndef QUEUE_H
#define QUEUE_H

#include "Patient.h"

struct QueueNode {
    Patient patient;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue();
    ~Queue();

    void enqueue(const Patient& p);
    bool dequeue(Patient& outPatient);
    void displayQueue() const;
    bool isEmpty() const;
};

#endif