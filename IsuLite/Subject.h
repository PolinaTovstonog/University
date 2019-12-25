#pragma once

#include <list>

#include "PersonList.h"
#include "Student.h"

using namespace std;

class subject {
	string _subjectName;
	map<int, list<int>*>* _studentsGrades = new map<int, list<int>*>;

	int getGrade(list<int>* gradeList) const;

public:
	subject(string &subjectName);

	void addStudent(int &studentId) const;
	void gradeStudent(int& studentId, int& grade) const;
	void closeSubject(personList* persons);
	void show() const;

	~subject();
};