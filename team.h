#include<vector>
#include "player.cpp"

class Team
{
public:
	Team();
	std::string name;
	int totalRunsScored;
	int wicketsLost;
	int totalBallsBowled;
	std::vector<Player>players;
};