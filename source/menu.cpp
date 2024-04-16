//
// Created by Rinki on 24-4-15.
//
#include <iostream>
#include "../header/model.h"
#include "../header/student.h"
#include "../header/file.h"

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

void informationOutput() {
    std::cout << "+-------------------------------------+" << std::endl;
    std::cout << "| 1. ID                               |" << std::endl;
    std::cout << "| 2. Name                             |" << std::endl;
    std::cout << "| 3. Usual score                      |" << std::endl;
    std::cout << "| 4. Exam score                       |" << std::endl;
    std::cout << "+-------------------------------------+" << std::endl;
}

void menuSelection(const MenuOptions option, std::vector<Student>& students) { // Function to take the choice from the user
    switch (option) {
        case MenuOptions::ADD_STUDENT:
            std::cout << "Add student(s)" << std::endl;
            addStudents(students);
            break;
        case MenuOptions::REMOVE_STUDENT:
            std::cout << "Remove student(s)" << std::endl;
            removeStudents(students);
            break;
        case MenuOptions::DISPLAY_STUDENT:
            std::cout << "Display student(s)" << std::endl;
            displayStudents(students);
            break;
        case MenuOptions::MODIFY_STUDENT:
            std::cout << "Modify student(s)" << std::endl;
            modifyStudents(students);
            break;
        case MenuOptions::QUERY:
            std::cout << "Query" << std::endl;
            query(students);
            break;
        case MenuOptions::STATISTICS:
            std::cout << "Statistics" << std::endl;
            statistics(students);
            break;
        case MenuOptions::EXIT:
            std::cout << "Exit" << std::endl;
            saveToFile(students);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    std::cout << std::endl;
}