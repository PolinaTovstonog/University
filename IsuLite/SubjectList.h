#pragma once

#include "Subject.h"

#include <string>

class subjectList {
	map<string, subject*>* _subjects = new map<string, subject*>;

public:
	
	void addSubject(string &subjectName) const;
	void addStudentToSubject(string& subjectName, int& studentId) const;
	void gradeStudent(string& subjectName, int& studentId, int& grade) const;
	void closeSubject(string& subjectName, personList* persons) const;
	void showSubject(string& subjectName) const;

	~subjectList();
};