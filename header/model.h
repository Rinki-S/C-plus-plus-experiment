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
    std::string id;
    std::string name;
    double usualScore;
    double examScore;
    double finalScore;
public:
    Student(std::string& id, std::string& name, const double inputUsualScore, const double inputExamScore) {
        id = std::move(id);
        name = std::move(name);
        usualScore = inputUsualScore;
        examScore = inputExamScore;
        finalScore = inputUsualScore * 0.2 + inputExamScore * 0.8;
    }

    void printStu() const {
        std::cout << "Student ID:" << id << std::endl;
        std::cout << "Student Name:" << name << std::endl;
        std::cout << "Usual GPA:" << usualScore << std::endl;
        std::cout << "Exam GPA:" << examScore << std::endl;
        std::cout << "Final GPA:" << finalScore << std::endl;
    }

    [[nodiscard]] int searchStudent(const std::string&& inputID) const {
        if (inputID == id) {
            return 1;
        }
        std::cout << "No such student!" << std::endl;
        return 0;
    }

    std::string getStudentID() {
		return id;
	}
    std::string getStudentName(){
		return name;
	}
	double getStudentUsualGPA() const{
		return usualScore;
	}
	double getStudentExamGPA(){
		return examScore;
	}
	double getStudentFinalGPA(){
		return finalScore;
	}
};
    void showGPAList();

    void deleteStudent(std::string id);

    void modifyStudent(std::string id);

    void statistics();


#endif //GRADE_MANAGEMENT_SYSTEM_MODEL_H