#include <fstream>

void saveToFile(const std::vector<Student>& students) {
	std::ofstream file("studentsList.txt");
	for (auto& student : students) {
		file << student.getID() << " " << student.getName() << " " << student.getUsualScore() << " " << student.getExamScore() << " " << student.getFinalScore() << std::endl;
	}
	file.close();
}

void loadFromFile(std::vector<Student>& students) {
	std::ifstream file("studentsList.txt");
	if (!file) {
		std::cout << "No file found." << std::endl;
		return;
	}
	std::string id;
	std::string name;
	double usualScore;
	double examScore;
	double finalScore;
	while (file >> id >> name >> usualScore >> examScore >> finalScore) {
		students.emplace_back(id, name, usualScore, examScore);
	}
	file.close();
}