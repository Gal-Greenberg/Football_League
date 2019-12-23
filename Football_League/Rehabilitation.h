#ifndef _REHABILITATION_H
#define _REHABILITATION_H

class Team;

class Rehabilitation
{
private:
	int numOfInjuredPlayers;
	double percentOfInjured;
	Team* team;
public:
	Rehabilitation(Team* team);
	//~Rehabilitation(); // removed from original H

	//set
	void setTeam(Team* newTeam);
	void setNumOfInjuredPlayers(int numOfInjuredPlayers);
	void setPercentOfInjured(double precentOfInjured);

	//get
	Team* getTeam() const;
	int getNumOfInjuredPlayers() const;
	double getPercentOfInjured() const;

	friend ostream& operator<<(ostream& os, const Rehabilitation& rehabilitation); // Add to original H
};

#endif