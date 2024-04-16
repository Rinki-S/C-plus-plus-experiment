//
// Created by Rinki on 24-4-16.
//

#ifndef FILE_H
#define FILE_H
#include <vector>
#include "student.h"

void saveToFile(const std::vector<Student>& students);
void loadFromFile(std::vector<Student>& students);

#endif //FILE_H
