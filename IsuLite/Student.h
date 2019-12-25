#pragma once

#include "Person.h"

#include <list>

class student : public person {
	struct SCourseWork_And_Diploma
	{
		string thesisTopic;
		string academicAdviser;

		SCourseWork_And_Diploma(string &thesis, string &adviser) {
			thesisTopic = thesis;
			academicAdviser = adviser;
		}
	};

private:
	list<pair<string, int>>* _courses = new list<pair<string, int>>;
	SCourseWork_And_Diploma* _courseWork = nullptr;
	list<int>* _grades = new list<int>;

public:
	student(string &name, int &id)
		:person(name, id) { }

	void addCourse(string &course, int grade) const;
	void setCourseWork(string &thesis, string adviser);
	void addGrade(int &grade) const;

	void viewInfo() override;
	~student() override;
};