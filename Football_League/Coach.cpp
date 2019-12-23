#include "Team.h"
#include "Coach.h"

Coach::Coach(const Person& person, int experienceYears, bool haveDiploma) : Person(person)
{
	setExperienceYears(experienceYears);
	setHaveDiploma(haveDiploma);
	setTeam(team);
}

void Coach::setExperienceYears(int experienceYears)
{
	if (experienceYears > 0)
		this->experienceYears = experienceYears;
	else
		throw "The number of experience years can't be less than one year";
}

void Coach::setHaveDiploma(bool haveDiploma)
{
	this->haveDiploma = haveDiploma;
}

void Coach::setTeam(Team* newTeam)
{
	if (newTeam != team)
	{
		team = newTeam;
		if (team != nullptr)
			team->setCoach(this);
	}
}

int Coach::getExperienceYears() const
{
	return experienceYears;
}

bool Coach::getHaveDiploma() const
{
	return haveDiploma;
}

Team* Coach::getTeam()
{
	return team;
}

bool Coach::operator==(const Coach& other) const
{
	if (experienceYears != other.experienceYears || haveDiploma != other.haveDiploma)
		return false;
	return true;
}

void Coach::print(ostream& os) const
{
	Person::print(os);
	os << " Coach: " << experienceYears << " years";
	if (haveDiploma)
		os << ", and have diploma";
	os << endl;
}