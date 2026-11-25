#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Patient.h"

struct ListNode {
    Patient patient;
    ListNode* next;
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList();
    ~LinkedList();

    bool addRecord(const Patient& p);
    ListNode* searchById(int id) const;
    bool updateRecord(int id, const std::string& newName, int newAge, const std::string& newCondition, bool newUrgent);
    bool deleteRecord(int id);
    void displayRecords() const;
};

#endif