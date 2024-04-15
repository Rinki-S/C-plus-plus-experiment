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
	void print() {
		cout << "学号：" << student_id << endl;
		cout << "姓名：" << student_name << endl;
		cout << "平时成绩：" << student_usual_gpa << endl;
		cout << "考试成绩：" << student_exam_gpa << endl;
		cout << "最终成绩：" << student_final_gpa << endl;
	}
	void show_gpalist();
	void delete_student(string id);
	void modify_student(string id);
	void stat_gpa();
};