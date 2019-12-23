#ifndef __RETIRED_PLAYER_H
#define __RETIRED_PLAYER_H

#include "State.h"

class Retire : public State
{
public:
	virtual void active(Player& p) const;
};

#endif