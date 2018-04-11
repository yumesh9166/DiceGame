#include "Dice.h"

Dice::Dice() {
	srand(time(0));//seeds and changes the algorythm of rand according to the clock on your computer
}
void Dice::updateUI(int caseNo){
	switch (caseNo) {
		case 1:
			cout << " ----- " << endl;
			cout << "|     |" << endl;
			cout << "|  O  |" << endl;
			cout << "|     |" << endl;
			cout << " ----- " << endl;
			break;
		case 2:
			cout << " -----"  << endl;
			cout << "|    O|" << endl;
			cout << "|     |" << endl;
			cout << "|O    |" << endl;
			cout << " -----"  << endl;
			break;
		case 3:
			cout << " -----"  << endl;
			cout << "|    O|" << endl;
			cout << "|  O  |" << endl;
			cout << "|O    |" << endl;
			cout << " -----" << endl;
			break;
		case 4:
			cout << " -----" << endl;
			cout << "|O   O|" << endl;
			cout << "|     |" << endl;
			cout << "|O   O|" << endl;
			cout << " -----" << endl;
			break;
		case 5:
			cout << " -----" << endl;
			cout << "|O   O|" << endl;
			cout << "|  O  |" << endl;
			cout << "|O   O|" << endl;
			cout << " -----" << endl;
			break;
		case 6:
			cout << " -----" << endl;
			cout << "|O   O|" << endl;
			cout << "|O   O|" << endl;
			cout << "|O   O|" << endl;
			cout << " -----" << endl;
			break;
	}
}

int Dice::roll() {
	int rollScore = 0;
	for (int i = 1; i <= DICE_FACE; i++) {
		int diceVal = (rand() % DICE_FACE) + 1;
		diceScore.setDiceVal(i,diceVal);
		cout << diceVal;
		updateUI(diceVal);
		rollScore += calculateScore(diceVal);
	}
	return rollScore;
}

int Dice::calculateScore(int diceVal)
{
	int rollScore = 0;
	if(1==diceVal)
	{
		rollScore += 100;
	}
	if(5==diceVal)
	{
		rollScore += 50;	
	}
	return rollScore;
}
 
int Dice::rollSingleDice(int DiceNo) {
	int diceVal = (rand() % DICE_FACE) + 1;
	cout << diceVal;
	diceScore.setDiceVal(DiceNo, diceVal);
	return calculateScore(diceVal);

}
int Dice::notScoredDice()
{
	int notScoredDice=0;
	for(int i=1;i<=DICE_FACE;i++)
	{
		if(!(diceScore.getDiceVal(i)==1||diceScore.getDiceVal(i)==5))
			notScoredDice++;	
	}
	return notScoredDice;
}
