//
// Created by Rinki on 24-4-15.
//
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include<string>
#include "../header/model.h"

bool checkDuplicateStudent(const std::vector<Student> &students, const std::string& id) { // Check if the student with the same ID already exists
    for (const auto &student : students) {
        if (student.searchStudent(id)) {
            return true;
        }
    }
    return false;
}

std::string studentIDInput() { // Input the student's ID
    std::cout << "Please enter the student's ID(the length should be 10 digits): ";
    std::string id;
    std::cin >> id;
    while (id.length() != 10 || !std::all_of(id.begin(), id.end(), ::isdigit)){
        std::cout << std::endl << "Your ID input is invalid, please input again: ";
        std::cin.clear();
        std::cin >> id;
    }
    std::cin.ignore();
    std::cin.clear();
    return id;
}

std::string studentNameInput() { // Input the student's name
    std::cout << "Please enter the student's name: ";
    std::string name;
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << std::endl << "Your name input is invalid, please input again: ";
        std::cin.clear();
        std::getline(std::cin, name);
    }
    std::cin.clear();
    return name;
}

double studentUsualScoreInput() { // Input the student's usual score
    std::cout << "Please enter the student's usual score: ";
    double score;
    std::cin >> score;
    bool errorState = std::cin.fail();
    while (errorState || score < 0 || score > 100){
        std::cout << std::endl << "Your usual score input is invalid, please input again: ";
        std::cin.clear();
        std::cin >> score;
        errorState = std::cin.fail();
    }
    std::cin.ignore();
    std::cin.clear();
    return score;
}

double studentExamScoreInput() { // Input the student's exam score
    std::cout << "Please enter the student's exam score: ";
    double score;
    std::cin >> score;
    bool errorState = std::cin.fail();
    while (errorState || score < 0 || score > 100){
        std::cout << std::endl << "Your exam score input is invalid, please input again: ";
        std::cin.clear();
        std::cin >> score;
        errorState = std::cin.fail();
    }
    std::cin.ignore();
    std::cin.clear();
    return score;
}

void printTableHead() { // Print the table head
    std::cout << std::left <<
        std::setw(15) << "ID" <<
            std::setw(15) << "Name" <<
                std::setw(15) << "Usual Score" <<
                    std::setw(15) << "Exam Score" <<
                        std::setw(15) << "Final Score" << std::endl;
}

bool compareID(const Student &a, const Student &b) { // Compare the ID of two students
    return a.getID() < b.getID();
}

bool informationChangeConfirmation() { // Confirm if the information is changed
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