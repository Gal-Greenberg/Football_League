#include "Active.h"
#include "Retire.h"

void Active::retire(Player& p) const
{
	p.setCurrent(new Retire());
	delete this;
}