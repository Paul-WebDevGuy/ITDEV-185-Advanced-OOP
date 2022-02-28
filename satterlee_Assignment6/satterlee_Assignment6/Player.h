#pragma once

#include "Die.h"

using namespace std;

/************************************
		Player Header File
*************************************/

class Player
{
private:
	Die die[20];
	int diceSum;
	int playerNumber = 0;

public:
	void Play();
	void SetPlayerNumber(int num);
	int GetNumOfDice();
	int GetPlayerNumber();
	int GetSingleDiceValue(int dieNum);
	int GetSumOfDice();

};

