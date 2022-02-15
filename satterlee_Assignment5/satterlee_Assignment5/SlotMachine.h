#pragma once
#include <string>
#include "Reel.h"


/*****************************************
			SLOT MACHINE HEADER FILE
******************************************/
class SlotMachine
{
private:
	bool isWinner;
	Reel game[3];
	
public:
	void play();
	bool getGameResult();
};

