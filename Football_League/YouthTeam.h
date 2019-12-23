#ifndef _YOUTHTEAM_H
#define _YOUTHTEAM_H
#include "Team.h"

class Coach;

class YouthTeam : public Team
{
private:
	int annual;
public:
	YouthTeam(const string& name,int annual);
	//YouthTeam(const char* name, int annual,Coach* coach = nullptr, ProfissionalAdvisor* profissionalAdvisor = nullptr);  // removed from original H

	//get
	int getAnnual() const;

	void setAnnual(int annual); // Add to original H

	virtual void print(ostream& os) const; // Add to original H
};

#endif