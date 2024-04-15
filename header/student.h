//
// Created by Rinki on 24-4-15.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "../header/model.h"

[[nodiscard]] int addStudents();
[[nodiscard]] int removeStudents();
[[nodiscard]] int displayStudents();
void modifyStudents();
int informationModify(Student student);
void query();
void statistics();

#endif //STUDENT_H
