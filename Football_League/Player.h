#ifndef _PLAYER_H
#define _PLAYER_H

#include "Person.h"

class Team;
class State;

class Player : virtual public Person
{
private:
	int shirtNumber;
	bool injured;
	Team* team;
	State* state;
public:
	Player(const Person& person, int shirtNumber, bool injured);
	//Player(const char* name, int age, int id, int shirtNumber, bool injured);  // removed from original H
	
	//set
	void setShirtNumber(int shirtNumber);
	void setInjured(bool injured);
	void setTeam(Team* newTeam);
	void setCurrent(State *s);

	//get
	int getShirtNumber() const;
	bool getInjured() const;
	Team* getTeam();

	void activePlayer();
	void retiredPlayer();

	virtual bool operator==(const Player& other) const; // Add to original H
	virtual void print(ostream& os) const; // Add to original H
};

#endif