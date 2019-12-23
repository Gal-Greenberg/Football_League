#include "Team.h"

Team::Team(const string& name)
{
	setName(name);
}

void Team::setScore(int score)
{
	if (score > 0)
		this->score = score;
	else
		throw "The score can't be less than one";
}

void Team::setCoach(Coach* newCoach)
{
	if (coach != newCoach)
	{
		if (coach != nullptr)
			coach->setTeam(nullptr);
		coach = newCoach;
		if (coach != nullptr)
			coach->setTeam(this);
	}
}

void Team::setProfissionalAdvisor(ProfissionalAdvisor* newProfissionalAdvisor)
{
	if (profissionalAdvisor != newProfissionalAdvisor)
	{
		if (profissionalAdvisor != nullptr)
			profissionalAdvisor->setTeam(nullptr);
		profissionalAdvisor = newProfissionalAdvisor;
		if (coach != nullptr)
			profissionalAdvisor->setTeam(this);
	}
}

void Team::setRehabilitation(Rehabilitation* newRehabilitation)
{
	if (rehabilitation != newRehabilitation)
	{
		if (rehabilitation != nullptr)
			rehabilitation->setTeam(nullptr);
		rehabilitation = newRehabilitation;
		if (rehabilitation != nullptr)
			rehabilitation->setTeam(this);
	}
}

void Team::setName(const string& name)
{
	teamName = name;
}

const string& Team::getName() const
{
	return teamName;
}

Coach* Team::getCoach() const
{
	return coach;
}

ProfissionalAdvisor* Team::getProfissionalAdvisor() const
{
	return profissionalAdvisor;
}

Rehabilitation* Team::getRehabilitation() const
{
	return rehabilitation;
}

int Team::getScore() const
{
	return score;
}

const Team& Team::operator+=(Player& newPlayer)
{
	for (Player* player : players)
		if (*player == newPlayer)
			return *this;

	players.push_back(&newPlayer);
	newPlayer.setTeam(this);
	return *this;
}

const Team& Team::operator-=(const Player& player)
{
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (*players[i] == player)
		{
			players[i]->setTeam(nullptr);
			players.erase(players.begin() + i);
			break;
		}
	}
	return *this;
}

const Team& Team::operator+=(Coach& other)
{
	if (coach != nullptr)
		throw "There is coach, if you want to replace you need to remove first";
	setCoach(&other);
	return *this;
}

const Team& Team::operator-=(const Coach& other)
{
	if (*coach == other) {
		coach = nullptr;
		setCoach(coach);
	}
	return *this;
}

bool Team::operator>=(const Team& other) const
{
	return score >= other.score;
}

bool Team::operator==(const Team& other) const
{
	return teamName == other.teamName && score == other.score;
}

void Team::print(ostream& os) const
{
	os << "Team: " << teamName << " Score: " << score << endl;

	if (rehabilitation != nullptr)
		os << *rehabilitation;
	if (coach != nullptr)
		os << *coach;
	if (profissionalAdvisor != nullptr)
		os << *profissionalAdvisor;

	for (Player* player : players)
	{
		os << *player;
	}
}

ostream& operator<<(ostream& os, const Team& team)
{
	team.print(os);
	return os;
}