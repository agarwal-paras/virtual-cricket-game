#include<iostream>
#include<limits>
#include<cstdlib>
#include<ctime>
#include<time.h>
#include "team.cpp"

class Game
{
public:
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];
	int target=0;

	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam, *bowlingTeam;
	Player *batsman, *bowler;
	Game();

	void welcome();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void scoreCard();
	void startSecondInnings();
	void swapteam(Team *,Team *);
	void gamesummary();
};
