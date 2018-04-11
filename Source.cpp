// Stephen Garrison
// 17SP_INFO_1532_9A
// Assignment 1
// Zilch game
// This program creates the Die and Players

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include <string>
//#include "newSet.h"


using namespace std;


int main() {
	int noOfPlayers;
	int rounds = 0;
	cout <<endl<< "\t\tWELCOME TO THE GAME OF ZILCH" << endl;
	cout << endl;

	cout << "Enter the number of players"<<endl;
	cin>>noOfPlayers;
	Player players[noOfPlayers+1];
	//only four player supported till now
	if(noOfPlayers>4){
		cout<<"max 4 player are allowed"<<endl;
		noOfPlayers = 4;
	}
	for(int i =1;i<=noOfPlayers;i++)
	{
		cout<<"Enter Player"<<i<<" name"<<endl;
		players[i].enterPlayerName();	
	}

	do {
		rounds++;
		int roundTopScore = 0;
		for(int i=1;i<=noOfPlayers;i++)
		{
			//check player choice
			if(!players[i].getPlayTurn(rounds))
				continue;
			char c;
			//cout<<"accumulated score:"<<players[i].getAccumulatedScore(rounds-1)<<endl;
			if(players[i].getAccumulatedScore(rounds-1)>=MELD_LIMIT)
			{
				//ask player about player choice
				cout<<players[i].getPlayerName()<<", press Y/y to continue playing the game and press N/n to stop playing"<<endl;
				cin>>c;
				while(!(c == 'y' || c == 'Y' || c == 'n' || c == 'N')){
					cin>>c;
				}
				if(c == 'n' || c == 'N')
				{	
					for(int j= rounds; j<=MAX_ROUND;j++)
					{
						players[i].setPlayTurn(j, false);	
					}
					continue;
				}
			}
			//ask player to roll the dice
			cout<<players[i].getPlayerName()<<", This is your turn. Please Enter 'Y/y' to roll the dice"<<endl;
			cin>>c;
			while(!(c == 'y' || c == 'Y')){
				cin>>c;
			}
			players[i].playerTurn(rounds);
			//set accumulated score
			players[i].setAccumulatedScore(rounds);
			cout<<players[i].getPlayerName()<<", your round:"<<rounds<<" score is:"<<players[i].getRoundScore(rounds)<<endl;
			if(0==players[i].getRoundScore(rounds))
			{	
				cout<<players[i].getPlayerName()<<", you are zilch'ed"<<endl;
			}
			if(roundTopScore < players[i].getRoundScore(rounds))
			{
				roundTopScore = players[i].getRoundScore(rounds);
			}
			players[i].updateRoundNumber(rounds);
		}
		cout<<endl;
		//calculate this round winner
		for(int i=1;i<=noOfPlayers;i++)
		{
			if(players[i].getRoundScore(rounds) == roundTopScore)
			{
				cout<<players[i].getPlayerName()<<" is the winner with score:"<<players[i].getRoundScore(rounds)<<endl;
			}
		}
		if(rounds<=4){
			cout << "would you like to play again(y/n): " << endl;
			char option;
			cin >> option;
			if (option == 'y' || option== 'Y')
				continue;
			else
				break;
		}
	} while (rounds <= 4);
	cout<<rounds<<" rounds played"<<endl;
	int scores[MAX_ROUND+1]={0,0,0,0,0,0}, highScore=0;
	//calculated high score 
	for(int i=1;i<=noOfPlayers;i++)
	{
		scores[i] = players[i].giveAccumulatedScoreAllRounds();
		if(highScore<scores[i])
		{
			highScore = scores[i];
		}
	}
	//cout<<"High Score:"<<highScore<<endl;
	//print the winners
	for(int i=1;i<=noOfPlayers;i++)
	{
		if(highScore == players[i].giveAccumulatedScoreAllRounds())
		{
			cout<<endl<<"****\t"<<players[i].getPlayerName()<<" is the winner of game with score: "<<players[i].giveAccumulatedScoreAllRounds()<<"\t****"<<endl<<endl;
		}
	}

	//system("exit");
	return 0;

}
