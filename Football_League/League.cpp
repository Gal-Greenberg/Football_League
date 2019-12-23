#include "League.h"

League::League(const string name)
{
	setName(name);
}

void League::setName(const string name)
{
	this->name = name;
}

int League::getNumberOfTeams() const
{
	return teams.size();
}

ostream& operator<<(ostream& os, const League& league)
{
	os << "League: " << league.name << endl;
	for (Team* team : league.teams)
		os << *team;
	return os;
}

Team* League::operator[](int index)
{
	return teams[index];
}

const League& League::operator+=(Team& team)
{
	teams.push_back(&team);
	return *this;
}

const League& League::operator-=(const Team& team)
{
	for (unsigned i = 0; i < teams.size(); i++)
	{
		if (*teams[i] == team)
		{
			teams.erase(teams.begin() + i);
			break;
		}
	}
	return *this;
}

void League::game(Team& team1, Team& team2)
{
	int randomWin = rand() % 2;
	if (randomWin == 0)
	{
		cout << team1.getName() << " Won!" << endl;
		team1.setScore(team1.getScore() + POINTS_FOR_WINNING);
	}
	else
	{
		cout << team2.getName() << " Won!" << endl;
		team2.setScore(team2.getScore() + POINTS_FOR_WINNING);
	}
}

void League::sortTeamsByPoints()
{
	for (unsigned i = 0; i < teams.size() - 1; i++)
		for (unsigned int j = 0; j < teams.size() - i - 1; j++)
			if (*teams[j + 1] >= *teams[j])
				swap(j, j + 1);
}

void League::swap(int i, int j)
{
	Team* temp = teams[i];
	teams[i] = teams[j];
	teams[j] = temp;
}