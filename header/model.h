#include<iostream>
using namespace std;
class Student {
private:
	string student_id;
	string student_name;
	float student_usual_gpa;
	float student_exam_gpa;
	float student_final_gpa;
public:
	Student(string id, string name, float usual_gpa, float exam_gpa) {
		student_id = id;
		student_name = name;
		student_usual_gpa = usual_gpa;
		student_exam_gpa = exam_gpa;
		student_final_gpa = usual_gpa * 0.2 + exam_gpa * 0.8;
	}
	void print_stu() {
		cout << "StudentID:" << student_id << endl;
		cout << "StudentName:" << student_name << endl;
		cout << "UsualGPA:" << student_usual_gpa << endl;
		cout << "ExmaGPA:" << student_exam_gpa << endl;
		cout << "FinalGPA:" << student_final_gpa << endl;
	}
	void search_student(string id) {
		if (id == student_id) {
			print_stu();
		}
		else {
			cout << "No such student!" << endl;
		}
	}
	void show_gpalist();
	void delete_student(string id);
	void modify_student(string id);
	void stat_gpa();
};