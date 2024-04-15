//
// Created by Rinki on 24-4-15.
//
#include <iostream>
#include <algorithm>

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