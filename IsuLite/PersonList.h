#pragma once

#include "Person.h"

#include <map>

class personList {
	map<int, person*>* _persons = new map<int, person*>;

public:
	void addPerson(person* p) const;
	person* getPerson(int id) const;
	void display() const;

	~personList();
};