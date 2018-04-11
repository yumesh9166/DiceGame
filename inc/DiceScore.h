#ifndef DiceScore_h
#define DiceScore_h
#define DICE_FACE 6
class DiceScore{
private:
	/*
	@brief
	Store the dices numbers 
	*/
	int set[DICE_FACE];
public:
	/*
	@brief
	Default constructor 
	*/
	DiceScore();

	/*
	@brief
	Default Destructor
	*/
	~DiceScore();

	/*
	@brief
	set the dice number
	@para
	diceNo: dice number 
	value: value that you want to store for dice no 
	*/
	void setDiceVal(int diceNo, int value);
	
	/*
	@brief
	set the dice number
	@para
	diceNo: dice number 
	@return
	value for the given dice number 
	*/
	int getDiceVal(int diceNo);
};
#endif
