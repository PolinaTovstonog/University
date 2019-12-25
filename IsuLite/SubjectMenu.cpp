#include "SubjectMenu.h"

#include <iostream>
#include <iomanip>
#include <conio.h>

subjectMenu::subjectMenu(subjectList* subjects, personList* persons) {
	_subjects = subjects;
	_persons = persons;
}

void subjectMenu::info()
{
	system("cls");

	cout << setw(40) << "Subject menu: " << endl;

	cout << "1. Add subject." << endl;
	cout << "2. Add student to subject." << endl;
	cout << "3. Grade student." << endl;
	cout << "4. Close subject." << endl;
	cout << "5. Show subject." << endl;

	cout << "0. Get back." << endl << endl;
	cout << ">>> ";
}

void subjectMenu::interact() const
{
	info();
	char command;
	while (cin >> command)
	{
		switch (command) {
		case '1': {
			string subjectName; cout << "Input subject name: "; 
			getline(cin, subjectName);
			getline(cin, subjectName);
			addSubject(subjectName);
			break;
		}
		case '2': {
			string subjectName; cout << "Input subject name: "; 
			getline(cin, subjectName);
			getline(cin, subjectName);
			int studentId; cout << "Input student's id: "; cin >> studentId;
			addStudentToSubject(subjectName, studentId);
			break;
		}
		case '3': {
			string subjectName; cout << "Input subject name: "; 
			getline(cin, subjectName);
			getline(cin, subjectName);
			int studentId; cout << "Input student's id: "; cin >> studentId;
			int grade; cout << "Input grade: "; cin >> grade;
			gradeStudent(subjectName, studentId, grade);
			break;
		}
		case '4': {
			string subjectName; cout << "Input subject name: "; 
			getline(cin, subjectName);
			getline(cin, subjectName);
			closeSubject(subjectName);
			break;
		}
		case '5':
		{
			string subjectName; cout << "Input subject name: "; 
			getline(cin, subjectName);
			getline(cin, subjectName);
			showSubject(subjectName);
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


void subjectMenu::addSubject(string& subjectName) const
{
	_subjects->addSubject(subjectName);
}

void subjectMenu::addStudentToSubject(string& subjectName, int& studentId) const
{
	_subjects->addStudentToSubject(subjectName, studentId);
}

void subjectMenu::gradeStudent(string& subjectName, int& studentId, int& grade) const
{
	_subjects->gradeStudent(subjectName, studentId, grade);
}

void subjectMenu::showSubject(string& subjectName) const
{
	_subjects->showSubject(subjectName);
}

void subjectMenu::closeSubject(string& subjectName) const
{
	_subjects->closeSubject(subjectName, _persons);
}
