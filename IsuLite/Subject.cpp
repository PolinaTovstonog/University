#include "Subject.h"
#include <numeric>
#include <iostream>

subject::subject(string& subjectName)
{
	_subjectName = subjectName;
}

void subject::addStudent(int& studentId) const
{
	_studentsGrades->insert(make_pair(studentId, new list<int>));
}

void subject::gradeStudent(int& studentId, int& grade) const
{
	_studentsGrades->at(studentId)->push_back(grade);
}

int subject::getGrade(list<int>* gradeList) const
{
	return static_cast<int>(rint(accumulate(gradeList->begin(), gradeList->end(), 0)
		/ static_cast<double>(gradeList->size())));
}

void subject::closeSubject(personList* persons) {
	for (auto it = _studentsGrades->begin(); it != _studentsGrades->end(); ++it)
	{
		const auto curStudent = dynamic_cast<student*>(persons->getPerson((*it).first));
		curStudent->addCourse(_subjectName, getGrade((*it).second));
	}
}

void subject::show() const
{
	for(auto it = _studentsGrades->begin(); it != _studentsGrades->end(); ++it)
	{
		cout << (*it).first << ": ";
		for(auto &g : *(*it).second)
		{
			cout << g << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

subject::~subject()
{
	for(auto &s : *_studentsGrades)
	{
		delete s.second;
	}
	delete _studentsGrades;
}
