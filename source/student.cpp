//
// Created by Rinki on 24-4-15.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include "../header/model.h"
#include "../header/tools.h"

[[nodiscard]] int addStudents(std::vector<Student> *students) {
    // Add student(s) to the list
    std::string id = studentIDInput();
    std::string name = studentNameInput();
    double usualScore = studentUsualScoreInput();
    double examScore = studentExamScoreInput();
    std::cout << "Current information of this student is:" << std::endl;
    std::cout << std::left <<
        std::setw(15) << "ID" <<
            std::setw(15) << "Name" <<
                std::setw(15) << "Usual Score" <<
                    std::setw(15) << "Exam Score" << std::endl;
    std::cout << std::left <<
        std::setw(15) << id <<
            std::setw(15) << name <<
                std::setw(15) << usualScore <<
                    std::setw(15) << examScore << std::endl;
    std::cout << "Do you want to add this student to the list? (Y/N)" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        std::cout << "The student is not added to the list." << std::endl;
        return 0;
    }
    std::cout << "The student is added to the list." << std::endl;
    students->emplace_back(id, name, usualScore, examScore);
    std::cout << "Do you want to add another student? (Y/N)" << std::endl;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        if(!addStudents(students)) {
            std::cout << "No more students are added." << std::endl;
            return 0;
        }
    }
    return 1;
}

[[nodiscard]] int removeStudents();

[[nodiscard]] int displayStudents();

[[nodiscard]] int modifyStudents();

[[nodiscard]] int query();

[[nodiscard]] int statistics();
