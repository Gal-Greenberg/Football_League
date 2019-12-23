#include "PersonAdapter.h"

PersonAdapter::PersonAdapter(const string& name, int birthYear, int id, int currentYear)
	: Person(name, 1, id), currentYear(currentYear), birthYear(birthYear)
{
	updateAge();
}

void PersonAdapter::updateAge()
{
	setAge(currentYear - birthYear);
}

int PersonAdapter::getBirthYear() const
{
	return birthYear;
}