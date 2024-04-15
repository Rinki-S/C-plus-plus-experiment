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
    std::string studentID;
    std::string studentName;
    double studentUsualGPA;
    double studentExamGPA;
    double studentFinalGPA;
public:
    Student(std::string&& id, std::string&& name, const double usualGPA, const double examGPA) {
        studentID = std::move(id);
        studentName = std::move(name);
        studentUsualGPA = usualGPA;
        studentExamGPA = examGPA;
        studentFinalGPA = usualGPA * 0.2 + examGPA * 0.8;
    }

    void printStu() const {
        std::cout << "Student ID:" << studentID << std::endl;
        std::cout << "Student Name:" << studentName << std::endl;
        std::cout << "Usual GPA:" << studentUsualGPA << std::endl;
        std::cout << "Exam GPA:" << studentExamGPA << std::endl;
        std::cout << "Final GPA:" << studentFinalGPA << std::endl;
    }

    int searchStudent(const std::string&& id) const {
        if (id == studentID) {
            return 1;
        }
        else {
            std::cout << "No such student!" << std::endl;
        }
    }

};
    void showGPAList();

    void showStudent(string id) {
        if (searchStudent(id) == 1){
			printStu();
        }
    };

    void deleteStudent(std::string id);

    void modifyStudent(std::string id);

    void statistics();


#endif //GRADE_MANAGEMENT_SYSTEM_MODEL_H