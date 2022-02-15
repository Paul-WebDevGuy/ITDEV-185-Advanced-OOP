#include "Reel.h"
#include <ctime>

using namespace std;

/*******************************************************
		IMPLEMENTATION CODE FOR REEL CLASS
********************************************************/



//Reel constructor that resets random time each
//time a new reel is instantiated
Reel::Reel()
{
	srand(time(0));
}

//Spin function spins the reel and randomly selects one of twenty elements from an array
void Reel::spin()
{
	
	string animals[20] = { "tiger", "lion", "bear", "seahorse", "elephant", "dragon", "dog", "cat", "whale", "dolphin", "shark",
					"snake", "spider", "giraffe", "zebra", "cow", "pig", "donkey", "alligator", "fish" };

	animalResult = animals[rand() % 20];	//select random animal from array and assign it to variable
}

//Returns the result of the spin
string Reel::getSpinResult()
{
	return animalResult;
}
