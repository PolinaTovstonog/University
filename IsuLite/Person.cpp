#include "Person.h"

person::person(string &name, int &id) {
    _name = name;
    _id = id;
}

person::~person()
{
    delete _role;
} 

int person::getIDNumber() const
{
    return _id;
}

string person::getName() const
{
    return _name;
}
