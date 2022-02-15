#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

/*****************************************
			REEL HEADER FILE
******************************************/
class Reel
{
private:
	string animalResult;

public:
	Reel();
	string animals;
	void spin();
	string getSpinResult();
};

