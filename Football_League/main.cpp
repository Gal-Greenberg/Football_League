#include <time.h>
#include "League.h"
#include "PersonAdapter.h"
#include "Team.h"
#include "YouthTeam.h"
#include "Player.h"
#include "Coach.h"
#include "ProfissionalAdvisor.h"
#include "Rehabilitation.h"
#include "Directory.h"

void main() 
{
	try
	{
		Directory& dire = Directory::getInstance();

		League league("League");
		Team barce("FC-Barcelona");
		Player player(PersonAdapter("Gabi", 1996, 20, 2019), 55, false);
		dire.addPlayer(&player);
		Coach coach1(PersonAdapter("David", 1964, 38, 2019), 15, true);
		dire.addCoach(&coach1);

		PersonAdapter p("Dani", 1961, 60, 2019);
		Coach c(p, 20, true);
		dire.addCoach(&c);
		Player pl(p, 18, false);
		dire.addPlayer(&pl);

		pl.retiredPlayer();
		ProfissionalAdvisor proAdvisor(p, c, pl, 5, 17);
		Rehabilitation rehabilitation(&barce);

		barce += player;
		barce += coach1;
		barce.setProfissionalAdvisor(&proAdvisor);
		league += barce;
		cout << "The League details:\n" << league << endl;

		Coach coach2(PersonAdapter("Shay", 1979, 30, 2019), 10, false);
		dire.addCoach(&coach2);
		barce -= coach1;
		barce += coach2;
		cout << "The League details:\n" << league << endl;

		Team toto("FC-Toto");
		toto += coach1;
		Player player2(PersonAdapter("Shlomi", 1997, 20, 2019), 8, false);
		dire.addPlayer(&player2);
		toto += player2;
		league += toto;
		cout << "The League details:\n" << league << endl;

		player2.retiredPlayer();
		cout << "The League details:\n" << league << endl;

		srand(static_cast<unsigned int>(time(NULL)));
		league.game(barce, toto); // 1
		league.game(barce, toto); // 2
		league.game(barce, toto); // 3
		league.game(barce, toto); // 4
		league.game(barce, toto); // 5
		league.game(barce, toto); // 6
		league.game(barce, toto); // 7
		cout << endl;

		cout << "The League details : " << league << endl;
		league.sortTeamsByPoints();
		cout << "The League details : " << league << endl;

		YouthTeam youthT("Tel Aviv", 2014);
		Coach coach3(PersonAdapter("Ro", 1979, 30, 2019), 10, false);
		dire.addCoach(&coach3);
		Player player3(PersonAdapter("Avi", 1997, 20, 2019), 8, false);
		dire.addPlayer(&player3);

		youthT += coach3;
		youthT += player3;
		league += youthT;
		cout << "The League details : " << league << endl;

		cout << "The Directory details:\n" << dire << endl;
	}
	catch (const string msg)
	{
		cout << msg << endl;
	}

	/*
	// Original main:
	League league("League");
	Team team1("FC-Barcelona");
	Player player(Person("Gabi", 23, 20), 55, false);
	Coach coach1(Person("David", 55, 38), 15, true);
	team1 += player;
	team1 += coach1;
	league += team1;
	cout << "The League details : " << league << endl;
	Coach coach2(Person("Shay", 40, 30), 10, false);
	team1.setCoach(&coach2);
	Team team2("FC-Toto");
	team2 += coach1;
	Player player2(Person("Shlomi", 22, 20), 8, false);
	team2 += player2;
	league += team2;
	league.game(team1, team2);
	cout << "The League details : " << league << endl;
	league.sortTeamsByPoints();
	Person p("Dani", 58, 60);
	Coach c(p, 20, true);
	Player pl(p, 18, false);
	ProfissionalAdvisor proAdvisor(p, c, pl, 5, 17);
	team1.setProfissionalAdvisor(&proAdvisor);
	Rehabilitation rehabilitation(&team1);
	cout << "The League details : " << league << endl;
	*/
	system("pause");
}