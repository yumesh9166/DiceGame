#include "Player.h"

void Player::ResetDetails(void)
{
	accumulatedScore[0] = 0;
	for(int i=1;i<=MAX_ROUND;i++)
	{
		roundsScore[i]=0;
		playTurn[i]=true;
		accumulatedScore[i] = 0;
	}
	roundNumber = 0;
}
//default constructor
Player::Player() {
	ResetDetails();
	name.clear();
}
//Option to enter the players name
Player::Player(string playerName){
	ResetDetails();
	name = playerName;
}
//option to get players name
void Player::enterPlayerName() {
	cin >> name;
}
string Player::getPlayerName() {
	return name;
}

//round counter
void Player::updateRoundNumber(int roundNo) {
	roundNumber = roundNo;
}
// players turn
void Player::playerTurn(int roundNo) {
	setRoundScore(roundNo, dice.roll());
}
// keeping track of score by round
int Player::getRoundScore(int roundNo)
{
	return roundsScore[roundNo];
}
// keeping track of score by round
void Player::setRoundScore(int roundNo, int score)
{
	roundsScore[roundNo] = score;
}
// returning the total score
int Player::giveAccumulatedScoreAllRounds() {
	return accumulatedScore[roundNumber];
}
void Player::setAccumulatedScore(int roundNo)
{
	accumulatedScore[roundNo]=accumulatedScore[roundNo-1]+getRoundScore(roundNo);
}
int Player::getAccumulatedScore(int roundNo){	
	return accumulatedScore[roundNo];
}
bool Player::getPlayTurn(int roundNo){
	return playTurn[roundNo]; 
}
void Player::setPlayTurn(int roundNo, bool status){
	playTurn[roundNo] = status; 
}
