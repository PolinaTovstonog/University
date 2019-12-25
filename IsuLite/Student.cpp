#include "Student.h"

#include <iostream>

student:: ~student()
{
	delete _courseWork;
	delete _grades;
	delete _courses;
}

void student::addCourse(string &course, int grade) const
{
	_courses->push_back(make_pair(course, grade));
}

void student::addGrade(int &grade) const
{
	_grades->push_back(grade);
}

void student::setCourseWork(string &thesis, string adviser) {
	_courseWork = new SCourseWork_And_Diploma(thesis, adviser);
}

void student::viewInfo() {
	cout << "ID " << _id << " Student " << _name << endl;

	if (!_grades->empty()) {
		cout << "Grades" << endl;
		for (int i : *_grades) {
			cout << i << " ";
		}

		cout << endl;
	}
	else {
		cout << "..." << endl;
	}

	cout << endl;

	if (!_courses->empty()) {
		cout << "Courses: " << endl;
		for (auto &s : *_courses) {
			cout << s.first << " " << s.second << "\n";
		}
	}
	else {
		cout << "Empty courses list" << endl;
	}
	cout << endl;

	if (_courseWork != nullptr) {
		cout << "Thesis: " << _courseWork->thesisTopic << "\t" << "Adviser: " << _courseWork->academicAdviser << endl;
	}
	else {
		cout << "Diploma not found" << endl;
	}
	cout << endl;
}