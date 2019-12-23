#include "State.h"
#include "Active.h"
#include "Retire.h"
#include "Team.h"
#include "Player.h"

Player::Player(const Person& person, int shirtNumber, bool injured) : Person(person)
{
	setShirtNumber(shirtNumber);
	setInjured(injured);
	state = new Active();
}

void Player::setShirtNumber(int shirtNumber)
{
	if (shirtNumber < 0)
		throw "The shirt number can't be less than zero year";
	this->shirtNumber = shirtNumber;
}

void Player::setInjured(bool injured)
{
	this->injured = injured;
}

void Player::setTeam(Team* newTeam)
{
	if (newTeam != team)
	{
		Team* tempTeam = team;
		team = newTeam;
		if (team != nullptr)
			*team += *this;
		else
			*tempTeam -= *this;
	}
}

void Player::setCurrent(State *s)
{
	state = s;
}

int Player::getShirtNumber() const
{
	return shirtNumber;
}

bool Player::getInjured() const
{
	return injured;
}

Team* Player::getTeam()
{
	return team;
}

void Player::activePlayer()
{
	state->active(*this);
}

void Player::retiredPlayer()
{
	state->retire(*this);
	setTeam(nullptr);
}

bool Player::operator==(const Player& other) const
{
	return shirtNumber == other.shirtNumber && injured == other.injured;
}

void Player::print(ostream& os) const
{
	Person::print(os);
	os << " Player: shirt number: " << shirtNumber;
	if (injured)
		os << ", injured";
	if (dynamic_cast<Retire*>(state) != nullptr) // if retired player
		os << ", retired";
	os << endl;
}