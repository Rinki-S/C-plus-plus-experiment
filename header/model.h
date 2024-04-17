#ifndef GRADE_MANAGEMENT_SYSTEM_MODEL_H
#define GRADE_MANAGEMENT_SYSTEM_MODEL_H
#include <iostream>
#include <iomanip>

enum class MenuOptions { // enum class is used to define a set of named constants
    ADD_STUDENT = 1,
    REMOVE_STUDENT,
    DISPLAY_STUDENT,
    MODIFY_STUDENT,
    QUERY,
    STATISTICS,
    EXIT
};

enum class InformationOptions { // enum class is used to define a set of named constants
    ID = 1,
    NAME,
    USUAL_SCORE,
    EXAM_SCORE
};

class Student { // Class to store the student information
private:
    std::string id;
    std::string name;
    double usualScore;
    double examScore;
    double finalScore; // final score is calculated as 20% of usual score and 80% of exam score

public:
    Student(std::string& id, std::string& name, const double inputUsualScore, const double inputExamScore) { // Constructor to initialize the student information
        this->id = id;
        this->name = name;
        usualScore = inputUsualScore;
        examScore = inputExamScore;
        finalScore = inputUsualScore * 0.2 + inputExamScore * 0.8;
    }

    std::string getID() const { // Getter function to get the student ID
        return id;
    }

    std::string getName() const { // Getter function to get the student name
		return name;
	}

    double getUsualScore() const { // Getter function to get the student's usual score
		return usualScore;
	}

    double getExamScore() const { // Getter function to get the student's exam score
        return examScore;
    }

    double getFinalScore() const { // Getter function to get the student's final score
        return finalScore;
    }

    void setID(std::string&& inputID) { // Setter function to set the student ID
        id = std::move(inputID);
    }

    void setName(std::string&& inputName) { // Setter function to set the student name
        name = std::move(inputName);
    }

    void setUsualScore(const double inputUsualScore) { // Setter function to set the student's usual score
        usualScore = inputUsualScore;
    }

    void setExamScore(const double inputExamScore) { // Setter function to set the student's exam score
        examScore = inputExamScore;
    }

    void scoreUpdate() { // Update the final score
        finalScore = usualScore * 0.2 + examScore * 0.8;
    }

    void printStu() const { // Print the student information
        std::cout << std::left <<
            std::setw(15) << id <<
                std::setw(15) << name <<
                    std::setw(15) << usualScore <<
                        std::setw(15) << examScore <<
                            std::setw(15) << finalScore << std::endl;
    }

    [[nodiscard]] bool searchStudent(const std::string& inputID) const { // Search the student by ID
        return id == inputID;
    }
};

#endif //GRADE_MANAGEMENT_SYSTEM_MODEL_H