#ifndef Player_h
#define Player_h
#include <iostream>
#include "Dice.h"
#include <string>

/* max 5 rounds are allowed to play */
#define MAX_ROUND 5

using namespace std;
/*
Player class to handle all the palyer related operations and to store the player Data.
*/
class Player
{
private:	
	/* Store each round score */
	int roundsScore[MAX_ROUND+1];
	
	/* accumulated Score */
	int accumulatedScore[MAX_ROUND+1];
	
	/* current round no */
	int roundNumber = 0;
	
	/* player Name */
	string name;
	
	/* want to play Turn */
	bool playTurn[MAX_ROUND+1];
		
	/* Dice object to roll */
	Dice dice;

public:
	/*
	@brief
	Default Constructor
	*/
	Player();
	
	/*
	@brief
	Parameterized Constructor
	@para
	name: Name of the player
	*/
	Player(string name);
	
	/*
	@brief
	ResetPlater Details
	*/
	void ResetDetails(void);
	
	/*
	@brief
	tacking player name from user
	*/
	void enterPlayerName();
	
	/*
	@brief
	to get player name
	@return
	player name returned
	*/
	string getPlayerName();

	/*
	@brief
	player turn to roll the dice
	@para
	roundNo: round number
	*/
	void playerTurn(int roundNo);
	
	/*
	@brief
	To get Score of a perticular round
	@para
	roundNo: round number
	@return 
	perticular round score
	*/
	int getRoundScore(int roundNo);
	
	/*
	@brief
	For setting up Score of a perticular round
	@para
	roundNo: round number
	score: score of the round
	*/
	void setRoundScore(int roundNo, int score);
	
	/*
	@brief
	to get accumulative score of all the rounds
	@return
	score: score of all the rounds
	*/
	int giveAccumulatedScoreAllRounds();
	
	/*
	@brief
	to get accumulative score of perticular rounds
	@para
	RoundNo: round number
	@return
	score: accumulative score till the roundNo`
	*/
	int getAccumulatedScore(int roundNo);
	
	/*
	@brief
	to set accumulative score of perticular rounds
	@para
	roundNo: round number
	*/
	void setAccumulatedScore(int roundNo);
	
	/*
	@brief
	update the current running round
	@para
	roundNo: round number
	*/
	void updateRoundNumber(int roundNo);

	/*
	@brief
	Is player want to play this turn
	@para
	roundNo: round number
	@return
	status of player choice 
	*/
	bool getPlayTurn(int roundNo);
	
	/*
	@brief
	set player choice 
	@para
	roundNo: round number
	staus: status about player choice 
	*/
	void setPlayTurn(int roundNo, bool status);
};
#endif

