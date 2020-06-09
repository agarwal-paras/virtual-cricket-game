#include "game.h"
#include<unistd.h>
#include<fstream>
using namespace std;

Game :: Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";
	
	isFirstInnings =false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

void Game :: welcome()
{
	cout<<"\n\t\t--------------------------------------------\n";
	cout<<"\t\t|=================CRIC-IN==================|\n";
	cout<<"\t\t|                                          |\n";
	cout<<"\t\t|      Welcome To Virtual Cricket Game     |\n";
	cout<<"\t\t--------------------------------------------\n\n";

	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|==================Instruction==================|\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|                                               |\n";
	cout<<"\t\t|1. Create 2 Teams(Team-A and Team-B with 4     |\n\t\t    players)from a given pool of 11 players.    |\n";
	cout<<"\t\t|2.lead the toess and decide the choice of play.|\n";
	cout<<"\t\t|3.Each innings will be of 6 balls.             |\n";
	cout<<"\t\t-------------------------------------------------\n";
	
	
	cout<<"\n\t\tPress Enter To Continue\n";
	getchar();
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|=================Pool of Players===============|\n";
	cout<<"\t\t-------------------------------------------------\n";
	

	int i;
	cout<<"\n";
	for(i=0;i<11;i++)
	{
		cout<<"\t\t\t"<<players[i]<<"\n";
	}

	cout<<"\n\t\tPress Enter To Continue\n";
	getchar();


}

bool Game::validateSelectedPlayer(int index)
{
	int n;
	vector<Player>players;
	players = teamA.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id == index)
		{
			return false;
		}
	}

	players = teamB.players;
	n=players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id == index)
				return false;
	}
	return true;
}

int Game::takeIntegerInput()
{
	int n;
	while(!(cin>>n))
	{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout<<"Please enter the valid input integer\n";		
	}
	
	return n;
}

void Game::selectPlayers()
{
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|=============Create Team-A and Team-B==========|\n";
	cout<<"\t\t-------------------------------------------------\n";
	
	for(int i=0;i<playersPerTeam;i++)
	{
		teamASelection:
			cout<<"\n Select player "<<i+1<<" For Team-A : ";

			int  playerIndexTeamA = takeIntegerInput();
			
			if(playerIndexTeamA < 0 || playerIndexTeamA > 10) {
				cout<<"\n Please select from the given players\n";
				goto teamASelection;
			}
			else if(! validateSelectedPlayer(playerIndexTeamA))
			{
				cout<<"\nThe Player Has already been Selected. Please select another Player\n";
				goto teamASelection;
			}
			else
			{	
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}
				
		
		teamBSelection:
		
			cout<<"\n Select player "<<i+1<<" For Team-B : ";
			
			int  playerIndexTeamB = takeIntegerInput();
			
			if(playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout<<"\n Please select from the given players\n";
				goto teamBSelection;
			}
			else if(! validateSelectedPlayer(playerIndexTeamB))
				{
					cout<<"\nThe Player Has already been Selected. Please select another Player\n";
					goto teamBSelection;
				}
			else
			{
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}	
}

void Game :: showTeamPlayers()
{
	vector<Player> teamAplayers = teamA.players;
	vector<Player> teamBplayers = teamB.players;

	cout<<"\n\n\t\t------------------------\t\t----------------------\n";
	cout<<"\t\t=========Team-A=========\t\t=========Team-B=======\n";
	cout<<"\t\t------------------------\t\t----------------------\n";

	for(int i=0;i<playersPerTeam;i++)
	{
		cout<<"\t\t   | "<< "[" << i+1 << "]" << teamAplayers[i].name << "\t|\t";
		cout<<"\t\t   | "<< "[" << i+1 << "]" << teamBplayers[i].name << "\t |" ;
		cout<<endl;
	} 
cout<<"\t\t------------------------\t\t----------------------\n";

cout<<endl<<"Press Enter To Toss...";
getchar();
}

void Game :: toss()
{
	cout<<endl;
	cout<<"\t\t------------------------\n";
	cout<<"\t\t--------Let's Toss------\n";
	cout<<"\t\t------------------------\n\n";

	srand(time(NULL));
	int randomValue = rand()%2;

	cout<<"Tossing the coin..."<<endl<<endl;
	usleep(2000000);
	switch(randomValue)
	{
		case 0:
			cout<<"Team-A wins the toss"<<endl<<endl;
			tossChoice(teamA);
			break;
		case 1:
			cout<<"Team-B wins the toss"<<endl<<endl;
			tossChoice(teamB);
			break;

	}
}

void Game:: tossChoice(Team tossWinnerTeam)
{
	cout<<"Enter 1 to bat or 2 to bowl first."<<endl;

	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(tossInput)
	{
		case 1:
			cout<<"\n"<<tossWinnerTeam.name<<" won the toss and chose to bat first"<<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0)
			{
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else
			{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		case 2:
			cout<<"\n"<<tossWinnerTeam.name<<" won the toss and chose to bowl first"<<endl<<endl;
			if(tossWinnerTeam.name.compare("Team-A")==0)
			{
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			else
			{
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			break;
		default:
			cout<<"Invalid input please try again"<<endl;
			tossChoice(tossWinnerTeam);
			break;
	}
}

void Game :: startFirstInnings()
{
	cout<<"\t\t ||| First Innings Starts |||\n\n";
	isFirstInnings = true;
	initializePlayers();
}
void swapteam(Team *a,Team *b)
{
	Team t;
	t = *a;
	*a = *b;
	*b = t;
	return ;
}
void Game :: startSecondInnings()
{
	cout<<"\n\n";
	cout<<"\t\t ||| Second Innings Starts |||\n\n";
	isFirstInnings = false;
	swap(battingTeam,bowlingTeam);
	initializePlayers();
}

void Game:: initializePlayers()
{
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout<<"\n"<<battingTeam->name<< " - "<<batsman->name<<" is batting "<<endl;
	cout<<"\n"<<bowlingTeam->name<< " - "<<bowler->name<<" is bowling "<<endl;
	
}

void Game :: scoreCard()
{
	cout<<"\t\t-------------------------------------------------------------------------------\n";
	cout<<"\t\t\t  "<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") | ";
	cout<<batsman->name<<" "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<")     ";
	cout<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<endl;
	cout<<"\t\t-------------------------------------------------------------------------------\n";
}

void Game::playInnings()
{
	for(int i=0;i<6;i++)
	{
		cout<<"Press Enter to bowl...";
		getchar();
		cout<<"Bowling..."<<endl;
		usleep(1000000);
		bat();
		if(!validateInningsScore())
		{
			break;
		}
	}

	fstream summary;
	summary.open("summary.txt",ios::out);
	if(!summary)
		cout<<"summary could not form";

	for(int i=0;i<playersPerTeam;i++)
	{
		summary<<i+1<<" "<<battingTeam->players[i].name<<"     "<<battingTeam->players[i].runsScored<<"  ("<<battingTeam->players[i].ballsPlayed<<")"<<endl;
	}


	for(int i=0;i<playersPerTeam;i++)
	{
		summary<<i+1<<" "<<bowlingTeam->players[i].name<<"     "<<bowlingTeam->players[i].runsScored<<"  ("<<bowlingTeam->players[i].ballsPlayed<<")"<<endl;
	}
	summary.close();
}

void Game:: bat()
{
	srand(time(NULL));
	int runsScored = rand()%7;

	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed +1;

	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled +=1;
	bowler->runsGiven +=runsScored;

	if (runsScored!=0)
	{
		cout<<"\n"<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
	}

	else
	{
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" OUT! "<<endl<<endl;
		battingTeam->wicketsLost +=1;
		bowler->wicketsTaken +=1;

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];

	}	

	scoreCard();

}

bool Game::validateInningsScore()
{
	if(isFirstInnings)
	{
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{	
			cout<<"\n\t\t ||| First Innings Ends ||| "<<endl<<endl<<endl;
			cout<<"\t\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - ("<<battingTeam->wicketsLost << ") "<<bowlingTeam->totalBallsBowled<<" ) "<<endl;
			cout<<"\t\t"<<bowlingTeam->name <<" need "<<battingTeam->totalRunsScored + 1<<" runs to win the match "<<endl<<endl; 
			target = battingTeam->totalRunsScored+1;
			cout<<target;
			return false;

		}
	}
	else
	{
		if(battingTeam->totalRunsScored >=target)
		{
			cout<<"\n\t\t ||| "<<battingTeam->name<<" wins the match by "<<battingTeam->totalRunsScored-(target-1)<<" runs |||"<<endl;  
			cout<<"\t\t "<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - ("<<battingTeam->wicketsLost << ") "<<bowlingTeam->totalBallsBowled<<" ) "<<endl;
			return false;
		}
		else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{	
			cout<<"\n\t\t ||| Second Innings Ends ||| "<<endl<<endl<<endl;
			cout<<"\t\t "<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - ("<<battingTeam->wicketsLost << ") "<<bowlingTeam->totalBallsBowled<<" ) "<<endl;
			if(battingTeam->totalRunsScored >= target)
				cout<<"\n\t\t ||| "<<battingTeam->name<<" wins the match by "<<battingTeam->totalRunsScored-(target-1)<<" runs |||"<<endl;  
			
			else if(battingTeam->totalRunsScored == target-1)
				cout<<"\n\t\t ||| The match was a tie and no team wins the match "<<endl;

			else
				cout<<"\n\t\t ||| "<<bowlingTeam->name<<" wins the match by "<<target-1 - (battingTeam->totalRunsScored)<<" runs |||"<<endl;  
			 
			return false;
		}
			
	}

	return true;
}


void Game:: gamesummary()
{
	cout<<"\n\nPress Enter to get match summary\n";
	getchar();
	cout<<"\n\n\n\t\t---------------------------------------------------------------\n";
	cout<<"\t\t=======================Match Summary===========================\n";
	cout<<"\t\t---------------------------------------------------------------\n";
	cout<<"\t\t|                                                             |\n";
	cout<<"\t\t|                            Team - A                         |\n";
	cout<<"\t\t|      ID  Name   Runs BallsPlayed                            |\n";
	cout<<"\t\t---------------------------------------------------------------\n";

	fstream summary;
	summary.open("summary.txt",ios::in);
	string s;
	int i=1;
while(std::getline(summary, s))
{
    cout <<"\t\t       "<< s <<"                                        \n"<< endl;
    if(i==4)
    	{
    		cout<<"\t\t---------------------------------------------------------------\n";
			cout<<"\t\t|                                                             |\n";
			cout<<"\t\t|                            Team - B                         |\n";
			cout<<"\t\t|      ID Name   Runs BallsPlayed                             |\n";
	
		}
    i++;
    cout<<"\t\t---------------------------------------------------------------\n";
																									
}    
	cout<<"\t\t===============================================================\n";

	cout<<"\n\n\t\t\t--------------------------------------------\n";
	cout<<"\t\t\t|=================CRIC-IN==================|\n";
	cout<<"\t\t\t|                                          |\n";
	cout<<"\t\t\t|                Thank-You                 |\n";
	cout<<"\t\t\t--------------------------------------------\n\n";
}
