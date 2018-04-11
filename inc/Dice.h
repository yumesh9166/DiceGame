#ifndef Dice_h
#define Dice_h
#include <iostream>
#include <string>
#include "DiceScore.h"
#define MELD_LIMIT 250
using namespace std;

/* Class to hold the dice properties and functions */
class Dice {
private:
	DiceScore diceScore;
public:
	/*
	@brief
	Default Constructor
	*/
	Dice();

	/*
	@brief
	update UI of Dice
	@para
	caseNo: directly related with dice face no
	*/
	void updateUI(int caseNo);
	
	/*
	@brief
	To Roll the dices
	@return
	score after rolling dices in one turn
	*/
	int roll();
	
	/*
	@brief
	calculate score of rolled dice
	@para
	diceVal: value of dice that rolled
	@return
	calculated score
	*/
	int calculateScore(int diceVal);
	
	/*
	@brief
	roll a single dice
	@para
	DiceNo: number of dice that you want to roll again
	@return
	score after rolling dice
	*/
	int rollSingleDice(int DiceNo);
	
	/*
	@brief
	calculate number of not scored dice
	@return
	number of not scored dice
	*/
	int notScoredDice();
};
#endif 
