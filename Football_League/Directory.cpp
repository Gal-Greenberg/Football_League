#include "Directory.h"

Directory::Directory()
{
	numOfCoaches = 0;
}

Directory::~Directory()
{
	for (Node<Coach*>* current = coachs.getFirst(); current != nullptr; current = current->getNext())
	{
		delete current->getData();
	}
}

int Directory::getNumOfPlayers()const
{
	return players.size();
}

int Directory::getNumOfCoaches()const
{
	return numOfCoaches;
}

void Directory::addPlayer(Player* player)
{
	players.push_back(player);
}

void Directory::removePlayer(Player* player)
{
	for (unsigned int i = 0; i < players.size(); i++)
	{
		if (player == players[i])
		{
			players.erase(players.begin() + i);
			break;
		}
	}
}

void Directory::addCoach(Coach *coach)
{
	coachs.insert(coach);
}

void Directory::removeCoach(Coach* coach)
{
	coachs.remove(coach);
}

ostream& operator<<(ostream& os, const Directory& directory)
{
	os << "All Players" << endl;
	for (Player* player : directory.players)
		os << *player;

	os << "All Coachs" << endl;
	directory.coachs.print();

	return os;
}