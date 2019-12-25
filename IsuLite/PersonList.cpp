#include "PersonList.h"

void personList::addPerson(person* p) const
{
	_persons->insert({p->getIDNumber(), p});
}

person* personList::getPerson(int id) const
{
	if (_persons->find(id) != _persons->end())
		return _persons->at(id);
	
	return nullptr;
}

void personList::display() const
{
	for (auto it = _persons->begin(); it != _persons->end(); ++it) {
		(*it).second->viewInfo();
	}
}

personList::~personList()
{
	for(auto &p : *_persons)
	{
		delete p.second;
	}
	delete _persons;
}
