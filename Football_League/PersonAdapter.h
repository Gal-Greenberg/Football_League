#ifndef _PERSON_ADAPTER_H
#define _PERSON_ADAPTER_H

#include "Person.h"

class PersonAdapter : public Person
{
private:
	int currentYear;
	int birthYear;
public:
	PersonAdapter(const string& name, int birthYear, int id, int currentYear);
	
	void updateAge();

	int getBirthYear() const;
};

#endif