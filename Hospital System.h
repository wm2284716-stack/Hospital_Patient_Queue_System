#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include "Linked List.h"
#include "Queue.h"
#include <string>

class HospitalSystem {
private:
    LinkedList records;
    Queue waitingQueue;

public:
    void registerPatient(int id, const std::string& name, int age, const std::string& condition, bool isUrgent);
    void callNextPatient();
    void showWaitingQueue() const;
    void searchPatient(int id) const;
    void updatePatient(int id, const std::string& newName, int newAge, const std::string& newCondition, bool newUrgent);
    void deletePatient(int id);
    void showAllRecords() const;
};

#endif