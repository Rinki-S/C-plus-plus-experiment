//
// Created by Rinki on 24-4-15.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include "../header/model.h"

int addStudents(std::vector<Student>& students);
int removeStudents(std::vector<Student>& students);
void displayStudents(std::vector<Student>& students);
void modifyStudents(std::vector<Student>& students);
int informationModify(Student& student, std::vector<Student> &students);
void query(const std::vector<Student>& students);
void statistics(const std::vector<Student>& students);

#endif //STUDENT_H
