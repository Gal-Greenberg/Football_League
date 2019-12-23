#include "Active.h"
#include "Retire.h"

void Retire::active(Player& p) const
{
	p.setCurrent(new Active());
	delete this;
}