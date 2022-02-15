#include "SlotMachine.h"
#include <iomanip>
#include <iostream>
using namespace std;


void SlotMachine::play()
{
	isWinner = false;		//turns true if all 3 reels land on same value
	
	//loop through game array and spin each reel, then display results
	for (int i = 0; i < 3; i++)
	{
		game[i].spin();
	}
	cout << left << setw(18) << game[0].getSpinResult() <<  setw(18) << game[1].getSpinResult() << setw(18) << game[2].getSpinResult() << endl;

	//check if all 3 reel results are the same value
	if ((game[0].getSpinResult() == game[1].getSpinResult()) && (game[1].getSpinResult() == game[2].getSpinResult()))
	{
		cout << endl;
		cout << "Winner!!!" << endl;
		isWinner = true;
	}
}

//return game result
bool SlotMachine::getGameResult()
{
	return isWinner;
}
