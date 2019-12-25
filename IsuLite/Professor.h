#pragma once

#include "Person.h"

#include <list>

class professor : public person {
	string _faculty;
	string _department;

	list<string>* _thesisTopics = new list<string>;
	list<string>* _publications = new list<string>;

public:
	professor(string &name, int &id, string &faculty, string &department)
		:person(name, id), _faculty(faculty), _department(department) { }

	void setFaculty(string& faculty);
	void setDepartment(string& department);
	void addThesisTopic(string& thesisTopic) const;
	void addPublication(string& publication) const;

	void viewInfo() override;
	~professor() override;
};