#ifndef _PROFISSIONALADVISOR_H
#define _PROFISSIONALADVISOR_H

#include "Coach.h"
#include "Player.h"

class Team;

class ProfissionalAdvisor : public Coach, public Player
{
private:
	int numberOfTeamHeCoachedBefore;
	int yearsOfPlayer;
	Team* team;
public:
	ProfissionalAdvisor(const Person& person, const Coach& coach, const Player& player,int numberOfTeamHeCoachedBefore,int yearsOfPlayer,Team* team=nullptr);//include the team here
	//ProfissionalAdvisor(const char* name, int age, int id, int experienceYears, bool haveDiploma, int shirtNumber, bool injured, int numberOfTeamHeCoachedBefore, int yearsOfPlayer);//include the team here  // removed from original H
	
	//set
	void setTeam(Team* team);
	void setNumberOfTeamHeCoachedBefore(int numberOfTeamHeCoachedBefore); // Add to original H
	void setYearsOfPlayer(int yearsOfPlayer); // Add to original H

	//get
	int getNumberOfTeamHeCoachedBefore() const;
	int getYearsOfPlayer() const;
	Team* getTeam();

	virtual void print(ostream& os) const; // Add to original H
};

#endif