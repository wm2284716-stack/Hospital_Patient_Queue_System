#include "Hospital System.h"
#include <iostream>
#include <string>
#include <limits>

namespace {
    int getInt(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::string getLine(const std::string& prompt) {
        std::string text;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, text);
            if (!text.empty()) {
                return text;
            }
            std::cout << "Input cannot be empty.\n";
        }
    }

    bool getPriority(const std::string& prompt) {
        while (true) {
            int p = getInt(prompt);
            if (p == 1) return true;
            if (p == 0) return false;
            std::cout << "Enter 1 for Urgent or 0 for Normal.\n";
        }
    }
}

int main() {
    HospitalSystem system;
    int choice = -1;

    do {
        std::cout << "\n=== Hospital Patient Queue System ===\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Call Next Patient\n";
        std::cout << "3. Display Waiting Queue\n";
        std::cout << "4. Search Patient by ID\n";
        std::cout << "5. Update Patient Record\n";
        std::cout << "6. Delete Patient Record\n";
        std::cout << "7. Display All Records\n";
        std::cout << "0. Exit\n";

        choice = getInt("Choice: ");

        switch (choice) {
        case 1: {
            int id = getInt("ID: ");
            std::string name = getLine("Name: ");
            int age = getInt("Age: ");
            std::string condition = getLine("Condition: ");
            bool urgent = getPriority("Priority (1 = Urgent, 0 = Normal): ");
            system.registerPatient(id, name, age, condition, urgent);
            break;
        }
        case 2:
            system.callNextPatient();
            break;
        case 3:
            system.showWaitingQueue();
            break;
        case 4: {
            int id = getInt("Enter ID to search: ");
            system.searchPatient(id);
            break;
        }
        case 5: {
            int id = getInt("Enter ID to update: ");
            std::string name = getLine("New Name: ");
            int age = getInt("New Age: ");
            std::string condition = getLine("New Condition: ");
            bool urgent = getPriority("New Priority (1 = Urgent, 0 = Normal): ");
            system.updatePatient(id, name, age, condition, urgent);
            break;
        }
        case 6: {
            int id = getInt("Enter ID to delete: ");
            system.deletePatient(id);
            break;
        }
        case 7:
            system.showAllRecords();
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}