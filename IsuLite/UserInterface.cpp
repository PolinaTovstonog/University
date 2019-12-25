#include "UserInterface.h"

#include <iostream>
#include <iomanip>
#include <conio.h>

userInterface::userInterface() {
	_personMenu = new personMenu(_persons);
	_subjectMenu = new subjectMenu(_subjects, _persons);
}

void userInterface::info() {
	system("cls");

	cout << setw(40) << "Main Menu: " << endl;

	cout << "1. Person menu." << endl;
	cout << "2. Grading system." << endl << endl;

	cout << "0. Exit" << endl << endl;
	cout << ">>> ";
}
	
void userInterface::interact() const
{
	info();
	
	char command;
	while (cin >> command) {
		switch (command)
		{
		case '1': {
			_personMenu->interact();
			break;
		}
		case '2': {
			_subjectMenu->interact();
			break;
		}
		case '0': {
			return;
		}
		default:
			cout << "Wrong command" << endl;
		}

		_getche();
		info();
	}
}
