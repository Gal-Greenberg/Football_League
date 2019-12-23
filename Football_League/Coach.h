#ifndef _COACH_H
#define _COACH_H
#include "Person.h"

class Team;

class Coach : virtual public Person
{
private:
	int experienceYears;
	bool haveDiploma;
	Team* team;
public:
	Coach(const Person& person,int experienceYears,bool haveDiploma);
	//Coach(const char* name, int age, int id, int experienceYears, bool haveDiploma);  // removed from original H

	//Set
	void setExperienceYears(int experienceYears);
	void setHaveDiploma(bool haveDiploma);
	void setTeam(Team* newTeam);

	//Get
	int getExperienceYears() const;
	bool getHaveDiploma() const;
	Team* getTeam();

	virtual bool operator==(const Coach& other) const; // Add to original H
	virtual void print(ostream& os) const; // Add to original H
};

#endif