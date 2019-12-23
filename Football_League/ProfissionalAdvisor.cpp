#include "Team.h"
#include "ProfissionalAdvisor.h"

ProfissionalAdvisor::ProfissionalAdvisor(const Person& person, const Coach& coach, const Player& player, int numberOfTeamHeCoachedBefore, int yearsOfPlayer, Team* team)
	: Person(person), Coach(coach), Player(player)
{
	setNumberOfTeamHeCoachedBefore(numberOfTeamHeCoachedBefore);
	setYearsOfPlayer(yearsOfPlayer);
	setTeam(team);
}

void ProfissionalAdvisor::setTeam(Team* newTeam)
{
	if (newTeam != team)
	{
		team = newTeam;
		if (team != nullptr)
			team->setProfissionalAdvisor(this);
	}
}

void ProfissionalAdvisor::setNumberOfTeamHeCoachedBefore(int numberOfTeamHeCoachedBefore)
{
	if (numberOfTeamHeCoachedBefore > 0)
		this->numberOfTeamHeCoachedBefore = numberOfTeamHeCoachedBefore;
	else
		throw "The number of team he coached before can't be less than one year";
}

void ProfissionalAdvisor::setYearsOfPlayer(int yearsOfPlayer)
{
	if (yearsOfPlayer > 0)
		this->yearsOfPlayer = yearsOfPlayer;
	else
		throw "The number years of player can't be less than one year";
}

int ProfissionalAdvisor::getNumberOfTeamHeCoachedBefore() const
{
	return numberOfTeamHeCoachedBefore;
}

int ProfissionalAdvisor::getYearsOfPlayer() const
{
	return yearsOfPlayer;
}

Team* ProfissionalAdvisor::getTeam()
{
	return team;
}

void ProfissionalAdvisor::print(ostream& os) const
{
	Player::print(os);
	Coach::print(os);
	os << " ProfissionalAdvisor: coached " << numberOfTeamHeCoachedBefore << " teams before, and played " << yearsOfPlayer << " years" << endl;
}