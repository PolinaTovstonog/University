#include "Professor.h"

#include <iostream>

professor::~professor()
{
	delete _thesisTopics;
	delete _publications;
}

void professor::setFaculty(string &faculty) {
	_faculty = faculty;
}

void professor::setDepartment(string& department) {
	_department = department;
}

void professor::addThesisTopic(string& thesisTopic) const
{
	_thesisTopics->push_back(thesisTopic);
}

void professor::addPublication(string& publication) const
{
	_publications->push_back(publication);
}

void professor::viewInfo() {
	cout << "ID " << _id << " Professor " << _name << endl;
	cout << "Faculty: " << _faculty << endl;
	cout << "Department: " << _department << endl << endl;

	if (!_thesisTopics->empty()) {
		cout << "Thesis topics: " << endl;
		for (string &s : *_thesisTopics) {
			cout << s << endl;
		}
	}
	else {
		cout << "Empty Thesis Topics list" << endl;
	}
	cout << endl;

	if (!_publications->empty()) {
		cout << "Publications: " << endl;
		for (string &s : *_publications) {
			cout << s << endl;
		}
	}
	else {
		cout << "Empty publications list" << endl;
	}
	cout << endl;
}