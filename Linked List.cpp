#include "Linked List.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

bool LinkedList::addRecord(const Patient& p) {
    if (searchById(p.id) != nullptr) {
        return false;
    }

    ListNode* newNode = new ListNode{ p, nullptr };
    if (head == nullptr) {
        head = newNode;
        return true;
    }

    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return true;
}

ListNode* LinkedList::searchById(int id) const {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->patient.id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool LinkedList::updateRecord(int id, const std::string& newName, int newAge, const std::string& newCondition, bool newUrgent) {
    ListNode* target = searchById(id);
    if (target == nullptr) {
        return false;
    }

    target->patient.name = newName;
    target->patient.age = newAge;
    target->patient.condition = newCondition;
    target->patient.isUrgent = newUrgent;
    return true;
}

bool LinkedList::deleteRecord(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head->patient.id == id) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    ListNode* prev = head;
    ListNode* current = head->next;
    while (current != nullptr && current->patient.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    prev->next = current->next;
    delete current;
    return true;
}

void LinkedList::displayRecords() const {
    if (head == nullptr) {
        std::cout << "\nNo patient records found.\n";
        return;
    }

    std::cout << "\n--- Patient Medical Records ---\n";
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << "ID: " << current->patient.id
            << " | Name: " << current->patient.name
            << " | Age: " << current->patient.age
            << " | Priority: " << (current->patient.isUrgent ? "Urgent" : "Normal")
            << " | Condition: " << current->patient.condition << "\n";
        current = current->next;
    }
}