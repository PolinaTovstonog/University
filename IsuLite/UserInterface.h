#pragma once

#include "PersonMenu.h"
#include "SubjectMenu.h"

#include <iostream>

class userInterface {
	personList* _persons = new personList;
	subjectList* _subjects = new subjectList;

	personMenu* _personMenu;
	subjectMenu* _subjectMenu;

public:
	static void info();
	void interact() const;

	userInterface();
};