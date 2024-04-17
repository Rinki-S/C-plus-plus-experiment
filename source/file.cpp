#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "../header/student.h"

void saveToFile(const std::vector<Student>& students) { // Save the students to the file
	std::ofstream file("studentsList.txt");
	if (!file) {
          std::cerr << "Error: File could not be opened." << std::endl;
		return;
	}
	for (auto& student : students) {
		file << student.getID() << std::endl << '"' << student.getName() << '"' << std::endl << student.getUsualScore() << std::endl << student.getExamScore() << std::endl << student.getFinalScore() << std::endl;
	}
	file.close();
}

void loadFromFile(std::vector<Student>& students) { // Load the students from the file
	std::ifstream file("studentsList.txt");
	if (!file) {
		std::cerr << "No file found." << std::endl;
		return;
	}
	std::string id;
	std::string name;
	double usualScore;
	double examScore;
	double finalScore;
	while (std::getline(file, id) && std::getline(file, name, '"') && std::getline(file, name, '"') && file >> usualScore >> examScore >> finalScore) {
		students.emplace_back(id, name, usualScore, examScore);
	}
	file.close();
}