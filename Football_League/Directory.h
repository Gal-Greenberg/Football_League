#ifndef _DIRECTORY_H
#define _DIRECTORY_H

#include <vector>
#include "LinkedList.h"
#include "Coach.h"
#include "Player.h"

class Directory
{
private:
	Directory(); // singleton directory

	vector<Player*> players;
	LinkedList<Coach*> coachs;
	int numOfCoaches;

public:
	~Directory();

	Directory(const Directory&) = delete; // singleton directory
	Directory& operator=(const Directory&) = delete;  // singleton directory

	static Directory& getInstance()
	{
		static Directory d;
		return d;
	}

	//set
	//void setNumOfPlayers(int numOfPlayers); // removed from original H
	//void setNumOfCoaches(int numOfCoaches); // removed from original H
	
	//get
	int getNumOfPlayers() const;
	int getNumOfCoaches() const;

	//other
	void addPlayer(Player* player);
	void removePlayer(Player* player);
	void addCoach(Coach* coach);
	void removeCoach(Coach* coach);

	friend ostream& operator<<(ostream& os, const Directory& directory); // Added to original H
};

#endif