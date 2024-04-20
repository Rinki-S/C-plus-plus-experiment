//
// Created by Rinki on 24-4-15.
//

#ifndef TOOLS_H
#define TOOLS_H
#include <string>
#include "model.h"

bool checkDuplicateStudent(const std::vector<Student> &students, const std::string &id);
std::string studentIDInput();
std::string studentNameInput();
double studentUsualScoreInput();
double studentExamScoreInput();
void printTableHead();
bool compareID(const Student &a, const Student &b);
bool informationChangeConfirmation();

#endif //TOOLS_H
