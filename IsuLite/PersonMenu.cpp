#include "PersonMenu.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

personMenu::personMenu(personList* persons) {
	_persons = persons;
}

void personMenu::info() const
{
	system("cls");
	
	cout << setw(40) << "Person menu: " << endl;
	cout << "1. Get person." << endl << endl;
	
	cout << "2. Add student." << endl;
	if(_curStudent)
	{
		cout << endl;
		cout << "Current student: " << _curStudent->getIDNumber() << ' ' << _curStudent->getName() << endl;
		cout << "3. Set course work." << endl;
	}
	cout << endl;

	cout << "4. Add professor." << endl;
	if(_curProfessor)
	{
		cout << endl;
		cout << "Current professor: " << _curProfessor->getIDNumber() << ' ' << _curProfessor->getName() << endl;
		cout << "5. Set faculty." << endl;
		cout << "6. Set department." << endl;
		cout << "7. Add publication." << endl;
	}
	cout << endl;

	cout << "8. Show all persons." << endl << endl;
	cout << "0. Get back." << endl << endl;
	cout << ">>> ";
}

void personMenu::interact()
{
	info();
	char command;
	while(cin >> command)
	{
		switch (command) {
		case '1': {
			int id; cout << "Input personal ID: "; cin >> id;
			getPerson(id);
			break;
		}
		case '2': {
			string name; cout << "Input student's name: "; 
			getline(cin, name);
			getline(cin, name);
			int id; cout << "Input student's ID: "; cin >> id;
			addStudent(name, id);
			break;
		}
		case '3': {
			string thesis; cout << "Input thesis: "; 
			getline(cin, thesis);
			getline(cin, thesis);
			int adviserId; cout << "Input adviser ID: "; cin >> adviserId;
			setCourseWork(thesis, adviserId);
			break;
		}
		case '4': {
			string name; cout << "Input professor's name: ";
			getline(cin, name);
			getline(cin, name);
			int id; cout << "Input professor's ID: "; cin >> id;
			string faculty; cout << "Input professor's faculty: "; 
			getline(cin, faculty);
			getline(cin, faculty);
			string department; cout << "Input professor's department: ";
			getline(cin, department);
			getline(cin, department);
			addProfessor(name, id, faculty, department);
			break;
		}
		case '5': {
			string faculty; cout << "Input professor's faculty: "; 
			getline(cin, faculty);
			getline(cin, faculty);
			setFaculty(faculty);
			break;
		}
		case '6': {
			string department; cout << "Input professor's department: "; 
			getline(cin, department);
			getline(cin, department);
			setDepartment(department);
			break;
		}
		case '7': {
			string publication; cout << "Input new publication: "; 
			getline(cin, publication);
			getline(cin, publication);
			addPublication(publication);
			break;
		}
		case '8': {
			showAll();
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

// StudentMenu
void personMenu::addStudent(string& name, int& id) {
	_curStudent = new student(name, id);
	_persons->addPerson(_curStudent);
}

void personMenu::setCourseWork(string& thesis, int& adviserId) const
{
	const auto curProfessor = dynamic_cast<professor*>(_persons->getPerson(adviserId));
	curProfessor->addThesisTopic(thesis);
	_curStudent->setCourseWork(thesis, curProfessor->getName());
}

// ProfessorMenu
void personMenu::addProfessor(string& name, int& id, string& faculty, string& department) {
	_curProfessor = new professor(name, id, faculty, department);
	_persons->addPerson(_curProfessor);
}

void personMenu::setFaculty(string& faculty) const
{
	_curProfessor->setFaculty(faculty);
}

void personMenu::setDepartment(string& department) const
{
	_curProfessor->setDepartment(department);
}

void personMenu::addPublication(string& publication) const
{
	_curProfessor->addPublication(publication);
}

// PersonMenu
void personMenu::getPerson(int& id) {
	const auto curPerson = _persons->getPerson(id);
	cout << "Current profile: ";

	const auto curStudent = dynamic_cast<student*>(curPerson);
	if (curStudent) {
		_curStudent = curStudent;
		cout << _curStudent->getIDNumber() << ' ' << _curStudent->getName();
		return;
	}

	_curProfessor = dynamic_cast<professor*>(curPerson);
	cout << _curProfessor->getIDNumber() << ' ' << _curProfessor->getName();
}

void personMenu::showAll() const
{
	system("cls");
	_persons->display();
}