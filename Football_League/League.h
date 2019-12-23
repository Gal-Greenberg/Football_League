#ifndef _LEAGUE_H
#define _LEAGUE_H

#include <string>
#include <iostream>
using namespace std;

#include"Team.h"

class League
{
private:
	static constexpr int MAX_NUMBER_OF_TEAM = 14;
	//static constexpr int MAX_NAME_LEN = 20; // removed from original H
	static const int POINTS_FOR_WINNING = 2; // Add to original H

	vector<Team*> teams;
	string name;

public:
	League(const string name);

	//set
	//void setNumberOfTeams(int numberOfTeams); // removed from original H
	void setName(const string name); // Add to original H

	//get
	int getNumberOfTeams() const;

	//operators
	friend ostream& operator<<(ostream& os, const League& league);
	Team* League::operator[](int index); // Changed from original H
	const League& operator+=(Team& other); // Changed from original H. const removed
	const League& operator-=(const Team& other);

	//other
	//void addTeamToLeague(Team *team); // removed from original H
	//void removeTeamFromLeague(Team *team); // removed from original H
	void game(Team& team1, Team& team2);
	void sortTeamsByPoints();
	void swap(int i, int j); // Add to original H
};
#endif