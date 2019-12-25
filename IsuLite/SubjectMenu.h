#pragma once

#include "SubjectList.h"

class subjectMenu {
	subjectList* _subjects;
	personList* _persons;

	static void info();
	
	void addSubject(string& subjectName) const;
	void addStudentToSubject(string& subjectName, int& studentId) const;
	void gradeStudent(string& subjectName, int& studentId, int& grade) const;
	void closeSubject(string& subjectName) const;
	void showSubject(string& subjectName) const;

public:
	void interact() const;
	subjectMenu(subjectList* subjects, personList* persons);
	~subjectMenu() = default;
};