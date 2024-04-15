#ifndef GRADE_MANAGEMENT_SYSTEM_MODEL_H
#define GRADE_MANAGEMENT_SYSTEM_MODEL_H
#include <iostream>

enum class MenuOptions {
    ADD_STUDENT = 1,
    REMOVE_STUDENT,
    DISPLAY_STUDENT,
    MODIFY_STUDENT,
    QUERY,
    STATISTICS,
    EXIT
};

class Student {
private:
    std::string student_id;
    std::string student_name;
    double student_usual_gpa;
    double student_exam_gpa;
    double student_final_gpa;
public:
    Student(std::string&& id, std::string&& name, double usual_gpa, double exam_gpa) {
        student_id = id;
        student_name = name;
        student_usual_gpa = usual_gpa;
        student_exam_gpa = exam_gpa;
        student_final_gpa = usual_gpa * 0.2 + exam_gpa * 0.8;
    }

    void printStu() const{
        std::cout << "Student ID:" << student_id << std::endl;
        std::cout << "Student Name:" << student_name << std::endl;
        std::cout << "Usual GPA:" << student_usual_gpa << std::endl;
        std::cout << "Exam GPA:" << student_exam_gpa << std::endl;
        std::cout << "Final GPA:" << student_final_gpa << std::endl;
    }

    void searchStudent(const std::string&& id) const{
        if (id == student_id) {
            printStu();
        } else {
            std::cout << "No such student!" << std::endl;
        }
    }

    void showGPAList();

    void deleteStudent(std::string id);

    void modifyStudent(std::string id);

    void statistics();
};

#endif //GRADE_MANAGEMENT_SYSTEM_MODEL_H