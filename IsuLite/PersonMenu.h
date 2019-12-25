#pragma once

#include "PersonList.h"

#include "Student.h"
#include "Professor.h"

class personMenu {
	personList* _persons;

	student* _curStudent = nullptr;
	professor* _curProfessor = nullptr;

	void info() const;

	void addStudent(string& name, int& id);
	void setCourseWork(string& thesis, int& adviserId) const;

	void addProfessor(string& name, int& id, string& faculty, string& department);
	void setFaculty(string& faculty) const;
	void setDepartment(string& department) const;
	void addPublication(string& publication) const;

	void getPerson(int& id);
	void showAll() const;

public:
	personMenu(personList* persons);
	~personMenu() = default;
	void interact();
};