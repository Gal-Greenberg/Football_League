#include "YouthTeam.h"

YouthTeam::YouthTeam(const string& name, int annual) : Team(name)
{
	setAnnual(annual);
}

int YouthTeam::getAnnual() const
{
	return annual;
}

void YouthTeam::setAnnual(int annual)
{
	this->annual = annual;
}

void YouthTeam::print(ostream& os) const
{
	os << "YouthTeam: " << annual << " annual" << endl;
	Team::print(os);
}