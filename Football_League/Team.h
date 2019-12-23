#ifndef __TEAM_H
#define __TEAM_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Coach.h"
#include "Player.h"
#include "ProfissionalAdvisor.h"
#include "Rehabilitation.h"

class Team
{
private:
	//static constexpr int MAX_PLAYER_IN_TEAM = 20;
	//static constexpr int MAX_NAME_LEN = 20; // removed from original H

	string teamName; //[MAX_NAME_LEN] // removed from original H
	vector<Player*> players;
	Coach* coach;
	Rehabilitation* rehabilitation;
	ProfissionalAdvisor* profissionalAdvisor;
	int score;

public:
	Team(const string& name);

	//set
	//void setNumOfPlayers(int numOfPlayers); // removed from original H
	void setScore(int score);
	void setCoach(Coach* newCoach);
	void setProfissionalAdvisor(ProfissionalAdvisor* profissionalAdvisor);
	void setRehabilitation(Rehabilitation* rehabilitation);
	void setName(const string& name); // Add to original H

	//get
	const string& getName() const;
	Coach* getCoach() const;
	ProfissionalAdvisor* getProfissionalAdvisor() const;
	Rehabilitation* getRehabilitation() const;
	int getScore() const; // Add to original H
	
	//operators
	const Team& operator+=(Player& other); // Changed from original H. const removed
	const Team& operator-=(const Player& other);
	const Team& operator+=(Coach& other); // Changed from original H. const removed
	const Team& operator-=(const Coach& other);
	bool operator>=(const Team& other) const; // Add to original H
	bool operator==(const Team& other) const;
	virtual void print(ostream& os) const; // Add to original H

	//other
	//void addPlayer(Player* newPlayer); // removed from original H
	//void removePlayer(Player* Player); // removed from original H
};

ostream& operator<<(ostream& os, const Team& team); // Add to original H
#endif