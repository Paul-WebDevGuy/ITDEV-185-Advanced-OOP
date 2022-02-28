#include "Player.h"

using namespace std;

/***********************************
	Player Implementation Code
************************************/

//Play function rolls all die in the die array and adds each die result to diceSum 
void Player::Play()
{
	diceSum = 0;
	int arrayBound = sizeof(die) / sizeof(die[0]);

	for (int i = 0; i < arrayBound; i++)
	{
		diceSum += die[i].roll();
	}
}

//Function to set the player number to keep track of all 100 individual players
void Player::SetPlayerNumber(int num)
{
	playerNumber = num;
}

//Returns number of dice being used by player
int Player::GetNumOfDice()
{
	return sizeof(die) / sizeof(die[0]);
}

//Returns players identifying number
int Player::GetPlayerNumber()
{
	return playerNumber;
}

//Returns individual dice value
int Player::GetSingleDiceValue(int dieNum)
{
	return die[dieNum].getValue();
}

//Returns total sum of all dice rolled
int Player::GetSumOfDice()
{
	return diceSum;
}
