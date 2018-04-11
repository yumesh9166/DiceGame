#include "DiceScore.h"
DiceScore::DiceScore()
{
	//Reset dice values
	for(int i=0;i<=DICE_FACE;i++)
	{
		set[i] = 0;
	}
}

DiceScore::~DiceScore()
{
}

void DiceScore::setDiceVal(int diceNo, int value)
{
	set[diceNo] = value;
}

int DiceScore::getDiceVal(int diceNo)
{
	return set[diceNo];
}
