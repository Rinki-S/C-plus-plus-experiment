//
// Created by Rinki on 24-4-15.
//
#include <iostream>

void menuOutput() { // Function to display the menu
    std::cout << "+-------------------------------------+" << std::endl;
    std::cout << "| 1. Add student(s)                   |" << std::endl;
    std::cout << "| 2. Remove student(s)                |" << std::endl;
    std::cout << "| 3. Display student(s)               |" << std::endl;
    std::cout << "| 4. Modify student(s)                |" << std::endl;
    std::cout << "| 5. Query                            |" << std::endl;
    std::cout << "| 6. Statistics                       |" << std::endl;
    std::cout << "| 7. Exit                             |" << std::endl;
    std::cout << "+-------------------------------------+" << std::endl;
}

void menuSelection(int choice) { // Function to take the choice from the user
    switch (choice) {
        case 1:
            std::cout << "Add student(s)" << std::endl;
            break;
        case 2:
            std::cout << "Remove student(s)" << std::endl;
            break;
        case 3:
            std::cout << "Display student(s)" << std::endl;
            break;
        case 4:
            std::cout << "Modify student(s)" << std::endl;
            break;
        case 5:
            std::cout << "Query" << std::endl;
            break;
        case 6:
            std::cout << "Statistics" << std::endl;
            break;
        case 7:
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    std::cout << std::endl;
}