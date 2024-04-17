//
// Created by Rinki on 24-4-15.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include "../header/menu.h"
#include "../header/model.h"
#include "../header/tools.h"

int addStudents(std::vector<Student> &students) {
    // Add student(s) to the list
    std::string id = studentIDInput();
    while (checkDuplicateStudent(students, id)) {
        std::cout << "The student with this ID already exists, please input again!" << std::endl;
        id = studentIDInput();
    }
    std::string name = studentNameInput();
    const double usualScore = studentUsualScoreInput();
    const double examScore = studentExamScoreInput();
    Student student(id, name, usualScore, examScore);
    std::cout << "Current information of this student is:" << std::endl;
    printTableHead();
    student.printStu();
    std::cout << "Do you want to add this student to the list? (Y/N)" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        std::cout << "The student is not added to the list." << std::endl;
        return 0;
    }
    std::cout << "The student is added to the list." << std::endl;
    students.emplace_back(student);
    std::cout << "Do you want to add another student? (Y/N)" << std::endl;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        if (!addStudents(students)) {
            std::cout << "No more students are added." << std::endl;
            return 0;
        }
    }
    return 1;
}

int removeStudents(std::vector<Student> &students) { // Remove student(s) from the list
    const std::string id = studentIDInput();
    bool isStudentExist = false;
    for (auto it = students.begin(); it != students.end(); ) {
        if (it->searchStudent(id)) {
            isStudentExist = true;
            std::cout << "The student with this ID is:" << std::endl;
            printTableHead();
            it->printStu();
            std::cout << "Do you want to remove this student from the list? (Y/N)" << std::endl;
            char choice;
            std::cin >> choice;
            if (choice != 'Y' && choice != 'y') {
                std::cout << "The student is not removed from the list." << std::endl;
                break;
            }
            students.erase(it);
            std::cout << "The student is removed from the list." << std::endl;
        } else {
            ++it;
        }
    }
    if (!isStudentExist) {
        std::cout << "The student with this ID does not exist." << std::endl;
        return 0;
    }
    std::cout << "Do you want to remove another student? (Y/N)" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        if (!removeStudents(students)) {
            std::cout << "No more students are removed." << std::endl;
            return 0;
        }
    }
    return 1;
}

void displayStudents(std::vector<Student> &students) { // Display student(s) in the list
    if (students.empty()) {
        std::cout << "No student is in the list." << std::endl;
        return;
    }
    std::sort(students.begin(), students.end(), compareID);
    printTableHead();
    for (const auto &student: students) {
        student.printStu();
    }
}

int informationModify(Student &student) { // Modify the information of the student
    std::cout << "Which part of the information do you want to change?" << std::endl;
    informationOutput();
    int choice;
    bool isInformationChanged = false;
    std::cin >> choice;
    while (choice < 1 || choice > 4) {
        std::cout << "Invalid input, please input again!" << std::endl;
        std::cin >> choice;
    }
    switch (static_cast<InformationOptions>(choice)) {
        case InformationOptions::ID: {
            std::string id = studentIDInput();
            if (informationChangeConfirmation()) {
                isInformationChanged = true;
                student.setID(std::move(id));
            }
            break;
        }
        case InformationOptions::NAME: {
            std::string name = studentNameInput();
            if (informationChangeConfirmation()) {
                isInformationChanged = true;
                student.setName(std::move(name));
            }
            break;
        }
        case InformationOptions::USUAL_SCORE: {
            const double usualScore = studentUsualScoreInput();
            if (informationChangeConfirmation()) {
                isInformationChanged = true;
                student.setUsualScore(usualScore);
                student.scoreUpdate();
            }
            break;
        }
        case InformationOptions::EXAM_SCORE: {
            const double examScore = studentExamScoreInput();
            if (informationChangeConfirmation()) {
                isInformationChanged = true;
                student.setExamScore(examScore);
                student.scoreUpdate();
            }
            break;
        }
        default:
            std::cout << "Invalid input." << std::endl;
            break;
    }
    return isInformationChanged;
}

void modifyStudents(std::vector<Student> &students) { // Modify student(s) in the list
    const std::string inputID = studentIDInput();
    for (auto &student: students) {
        if (student.searchStudent(inputID)) {
            std::cout << "The student with this ID is:" << std::endl;
            printTableHead();
            student.printStu();
            if (!informationModify(student))
                return;
            std::cout << "Do you want to modify another part of this student's information? (Y/N)" << std::endl;
            char choice;
            std::cin >> choice;
            while (choice == 'Y' || choice == 'y') {
                if (!informationModify(student))
                    return;
                std::cout << "Do you want to modify another part of this student's information? (Y/N)" << std::endl;
                std::cin >> choice;
            }
        }
    }
}


void query(const std::vector<Student> &students) { // Query student(s) in the list
    const std::string inputID = studentIDInput();
    for (auto &student: students) {
        if (student.searchStudent(inputID)) {
            std::cout << "The student with this ID is:" << std::endl;
            printTableHead();
            student.printStu();
            return;
        }
    }
    std::cout << "The student with this ID does not exist." << std::endl;
}

void statistics(const std::vector<Student> &students) { // Display the statistics of the students
    if (students.empty()) {
        std::cout << "No student is in the list." << std::endl;
        return;
    }
    double sum = 0;
    int gradeA = 0;
    int gradeB = 0;
    int gradeC = 0;
    int gradeD = 0;
    int gradeF = 0;
    for (const auto &student: students) {
        sum += student.getFinalScore();
        if (student.getFinalScore() >= 90) {
            gradeA++;
        } else if (student.getFinalScore() >= 80) {
            gradeB++;
        } else if (student.getFinalScore() >= 70) {
            gradeC++;
        } else if (student.getFinalScore() >= 60) {
            gradeD++;
        } else {
            gradeF++;
        }
    }
    std::cout << "The average final score of all students is: " << sum / students.size() << std::endl;
    std::cout << "The number of students whose score is above 90 is: " << gradeA << std::endl;
    std::cout << "The number of students whose score is between 80 and 90 is: " << gradeB << std::endl;
    std::cout << "The number of students whose score is between 70 and 80 is: " << gradeC << std::endl;
    std::cout << "The number of students whose score is between 60 and 70 is: " << gradeD << std::endl;
    std::cout << "The number of students whose score is below 60 is: " << gradeF << std::endl;
}
