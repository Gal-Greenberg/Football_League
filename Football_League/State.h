#ifndef __STATE_H
#define __STATE_H

#include "Player.h"

class State
{
public:
	virtual void active(Player& p) const {}
	virtual void retire(Player& p) const {}
};

#endif