#include <vector>
#include "../header/model.h"

bool compareStudentID(Student s1, Student s2) {
	return s1.getStudentID() < s2.getStudentID();
}
void showGPAList(std::vector<Student> students) {
	auto it=students.begin();
	std::sort(students.begin(), students.end(), compareStudentID));
	for (it; it != students.end(); ++it)
	{
		it->printStu();
	}
}

// void show_gpalist(const std::vector<Student>& students) {
// 	for (const auto& student : students) {
// 		student.printStu();
// 	}
// }