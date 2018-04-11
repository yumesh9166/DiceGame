At max four player can play at same time
you can compile by using below command
  g++ -o main -std=c++0x Dice.h Dice.cpp Player.h Player.cpp Source.cpp
after successful compilation binary will be created with name 'main'
so run the binary with below command and follow the steps
  ./main

version 2.0
command for compile the code is changed as i included one directory for header files
  g++ -o main -std=c++0x -Iinc DiceScore.cpp Dice.cpp Player.cpp Source.cpp
This version is released with all the feature set required 
Player Attributes
	Name: Player class have getPlayerName api
	Accumulative Score: Player class have getAccumulatedScore api
	Current Score: Player class have getRoundScore api

Player Actions
	Play A turn: Player class have playerTurn api
	Playing or Stop playing: decided based on MELD_LIMIT

Dice Set Attributes
	not scored dice: notScoredDice api will return the number of non scored dice
	Array of six dice: set is the array for all dice

Dice Set Actions
	Roll The unscored dice: notScoredDice api will return the number of non scored dice and by using rollSingleDice api we can roll a single dice
	Score the Rolled Dice: all the rolled dice score is stored in set array
 
Dice Attributes
	current value of die: set array contain current value of die in each round

Dice Actions
	Roll the die: roll and rollSingleDice api's are provided to roll all and single dice


all other mentioned actions also take care in it.
 
