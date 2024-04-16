#include <fstream>

std::ofstream file("studentsList.txt");
for (auto& student : students) {
	file << student.getID() << " " << student.getName() << " " << student.getUsualScore() << " " << student.getExamScore() << " " << student.getFinalScore() << std::endl;
}

file.close();