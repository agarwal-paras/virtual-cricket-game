#include "game.cpp"
using namespace std;


int main()
{
	Game g;
	g.welcome();
	g.selectPlayers();
	g.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	g.toss();
	g.startFirstInnings();
	g.playInnings();
	g.startSecondInnings();
	g.playInnings();
	g.gamesummary();
	return 0;
}