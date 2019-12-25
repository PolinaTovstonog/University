#include "SubjectList.h"

void subjectList::addSubject(string& subjectName) const
{
	_subjects->insert(make_pair(subjectName, new subject(subjectName)));
}

void subjectList::addStudentToSubject(string& subjectName, int& studentId) const
{

	_subjects->at(subjectName)->addStudent(studentId);
}

void subjectList::gradeStudent(string& subjectName, int& studentId, int& grade) const
{
	_subjects->at(subjectName)->gradeStudent(studentId, grade);
}

void subjectList::closeSubject(string& subjectName, personList* persons) const
{
	auto subject = _subjects->at(subjectName);
	subject->closeSubject(persons);
	delete subject;
	_subjects->erase(subjectName);
}

void subjectList::showSubject(string& subjectName) const
{
	_subjects->at(subjectName)->show();
}

subjectList::~subjectList()
{
	for(auto &s : *_subjects)
	{
		delete s.second;
	}
	delete _subjects;
}

