#ifndef GRADE_MANAGEMENT_SYSTEM_MODEL_H
#define GRADE_MANAGEMENT_SYSTEM_MODEL_H
#include <iostream>
#include <iomanip>

enum class MenuOptions {
    ADD_STUDENT = 1,
    REMOVE_STUDENT,
    DISPLAY_STUDENT,
    MODIFY_STUDENT,
    QUERY,
    STATISTICS,
    EXIT
};

enum class InformationOptions {
    ID = 1,
    NAME,
    USUAL_SCORE,
    EXAM_SCORE
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

    std::string getID() const {
        return id;
    }

    std::string getName() const {
		return name;
	}

    double getUsualScore() const {
		return usualScore;
	}

    double getExamScore() const {
        return examScore;
    }

    double getFinalScore() const {
        return finalScore;
    }

    void setID(std::string&& inputID) {
        id = std::move(inputID);
    }

    void setName(std::string&& inputName) {
        name = std::move(inputName);
    }

    void setUsualScore(const double inputUsualScore) {
        usualScore = inputUsualScore;
    }

    void setExamScore(const double inputExamScore) {
        examScore = inputExamScore;
    }

    void scoreUpdate() {
        finalScore = usualScore * 0.2 + examScore * 0.8;
    }

    void printStu() const {
        std::cout << std::left <<
            std::setw(15) << id <<
                std::setw(15) << name <<
                    std::setw(15) << usualScore <<
                        std::setw(15) << examScore << std::endl;
    }

    [[nodiscard]] bool searchStudent(const std::string& inputID) const {
        return id == inputID;
    }
};

#endif //GRADE_MANAGEMENT_SYSTEM_MODEL_H