//
// Created by Rinki on 24-4-15.
//
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../header/model.h"

bool checkDuplicateStudent(const std::vector<Student> &students, const std::string &id) {
    for (const auto &student : students) {
        if (student.searchStudent(id)) {
            return true;
        }
    }
    return false;
}

std::string studentIDInput() {
    std::cout << "Please enter the student's ID(the length should be 10 digits): ";
    std::string id;
    std::cin >> id;
    while (id.length() != 10 || !std::all_of(id.begin(), id.end(), ::isdigit)){
        std::cout << std::endl << "Your input is invalid, please input again: ";
        std::cin >> id;
    }
    return id;
}

std::string studentNameInput() {
    std::cout << "Please enter the student's name: ";
    std::string name;
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << std::endl << "Your input is invalid, please input again: ";
        std::getline(std::cin, name);
    }
    return name;
}

double studentUsualScoreInput() {
    std::cout << "Please enter the student's usual score: ";
    double score;
    bool errorState = std::cin.fail();
    while (errorState || score < 0 || score > 100){
        std::cout << std::endl << "Your input is invalid, please input again: ";
        std::cin.clear();
        std::cin >> score;
        errorState = std::cin.fail();
    }
    return score;
}

double studentExamScoreInput() {
    std::cout << "Please enter the student's exam score: ";
    double score;
    bool errorState = std::cin.fail();
    while (errorState || score < 0 || score > 100){
        std::cout << std::endl << "Your input is invalid, please input again: ";
        std::cin.clear();
        std::cin >> score;
        errorState = std::cin.fail();
    }
    return score;
}

void printTableHead() {
    std::cout << std::left <<
        std::setw(15) << "ID" <<
            std::setw(15) << "Name" <<
                std::setw(15) << "Usual Score" <<
                    std::setw(15) << "Exam Score" << std::endl;
}

bool compareID(const Student &a, const Student &b) {
    return a.getID() < b.getID();
}

bool informationChangeConfirmation() {
    std::cout << "Do you want to change the information? (Y/N)" << std::endl;
    char choice;
    std::cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        std::cout << "Information is not modified." << std::endl;
        return false;
    }
    std::cout << "Information is modified." << std::endl;
    return true;
}