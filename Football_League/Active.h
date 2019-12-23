#ifndef __ACTIVE_PLAYER_H
#define __ACTIVE_PLAYER_H

#include "State.h"

class Active : public State
{
public:
	virtual void retire(Player& p) const;
};

#endif