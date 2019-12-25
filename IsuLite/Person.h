#pragma once

#include <string>
#include <list>
using namespace std;

class person {
protected:
    string _name;
    int _id;
    list<string>* _role = new list<string>;

    person(string &name, int &id);

public:
    //enum type { Student, Professor };

    int getIDNumber() const;
    string getName() const;

    virtual void viewInfo() = 0;
    virtual ~person();
};