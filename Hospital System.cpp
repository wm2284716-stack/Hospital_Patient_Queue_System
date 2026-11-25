#include "Hospital System.h"
#include <iostream>

void HospitalSystem::registerPatient(int id, const std::string& name, int age, const std::string& condition, bool isUrgent) {
    if (id <= 0) {
        std::cout << "\nError: ID must be a positive number.\n";
        return;
    }
    if (age <= 0 || age > 130) {
        std::cout << "\nError: Age must be between 1 and 130.\n";
        return;
    }

    Patient p{ id, name, age, condition, isUrgent };
    if (!records.addRecord(p)) {
        std::cout << "\nError: Patient ID " << id << " already exists.\n";
        return;
    }

    waitingQueue.enqueue(p);
    std::cout << "\nPatient registered successfully.\n";
}

void HospitalSystem::callNextPatient() {
    Patient next;
    if (!waitingQueue.dequeue(next)) {
        std::cout << "\nNo patients waiting in the queue.\n";
        return;
    }

    std::cout << "\n--- Next Patient ---\n";
    std::cout << "ID: " << next.id
        << " | Name: " << next.name
        << " | Age: " << next.age
        << " | Priority: " << (next.isUrgent ? "Urgent" : "Normal")
        << " | Condition: " << next.condition << "\n";
}

void HospitalSystem::showWaitingQueue() const {
    waitingQueue.displayQueue();
}

void HospitalSystem::searchPatient(int id) const {
    ListNode* found = records.searchById(id);
    if (found == nullptr) {
        std::cout << "\nPatient with ID " << id << " not found.\n";
        return;
    }

    std::cout << "\n--- Patient Found ---\n";
    std::cout << "ID: " << found->patient.id
        << " | Name: " << found->patient.name
        << " | Age: " << found->patient.age
        << " | Priority: " << (found->patient.isUrgent ? "Urgent" : "Normal")
        << " | Condition: " << found->patient.condition << "\n";
}

void HospitalSystem::updatePatient(int id, const std::string& newName, int newAge, const std::string& newCondition, bool newUrgent) {
    if (newAge <= 0 || newAge > 130) {
        std::cout << "\nError: Age must be between 1 and 130.\n";
        return;
    }

    if (!records.updateRecord(id, newName, newAge, newCondition, newUrgent)) {
        std::cout << "\nPatient with ID " << id << " not found.\n";
        return;
    }

    std::cout << "\nPatient record updated successfully.\n";
}

void HospitalSystem::deletePatient(int id) {
    if (!records.deleteRecord(id)) {
        std::cout << "\nPatient with ID " << id << " not found.\n";
        return;
    }

    std::cout << "\nPatient record deleted successfully.\n";
}

void HospitalSystem::showAllRecords() const {
    records.displayRecords();
}