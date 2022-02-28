#include "Die.h"
#include <ctime>
#include <cstdlib>


using namespace std;

/****************************************
	Implementation Code for Die Class
*****************************************/

//Die constructor resets random time each time a new die is instantiated
Die::Die()
{
	srand(time(0));
}

//roll function randomly selects a number between 1 and 6 to simulate rolling a dice
int Die::roll()
{
	dieResult = rand() % 6 + 1;
	return dieResult;
}

//getValue function returns the result of the most recent dice roll
int Die::getValue()
{
	return dieResult;
}
