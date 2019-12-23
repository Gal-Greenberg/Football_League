#include "Team.h"
#include "Rehabilitation.h"

Rehabilitation::Rehabilitation(Team *team)
{
	setTeam(team);
}

void Rehabilitation::setTeam(Team* newTeam)
{
	if (newTeam != team)
	{
		team = newTeam;
		if (team != nullptr)
			team->setRehabilitation(this);
	}
}

void Rehabilitation::setNumOfInjuredPlayers(int numOfInjuredPlayers)
{
	if (numOfInjuredPlayers >= 0)
		this->numOfInjuredPlayers = numOfInjuredPlayers;
	else
		throw "The num of injured players can't be less than zero";
}

void Rehabilitation::setPercentOfInjured(double precentOfInjured)
{
	if (precentOfInjured >= 0)
		this->percentOfInjured = precentOfInjured;
	else
		throw "The precent of injured can't be less than zero";
}

Team* Rehabilitation::getTeam() const
{
	return team;
}

int Rehabilitation::getNumOfInjuredPlayers() const
{
	return numOfInjuredPlayers;
}

double Rehabilitation::getPercentOfInjured() const
{
	return percentOfInjured;
}

ostream& operator<<(ostream& os, const Rehabilitation& rehabilitation)
{
	os << "Rehabilitation, number of injured players: " << rehabilitation.numOfInjuredPlayers << ", percent of injured" 
		<< rehabilitation.percentOfInjured << endl;
	return os;
}