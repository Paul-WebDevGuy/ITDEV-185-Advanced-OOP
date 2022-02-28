#pragma once
#include <string>
#include <ctime>
#include<cstdlib>

using namespace std;
/***********************************
		Die Header File
************************************/
class Die
{
private: 
	int dieResult;
public:
	Die();
	int roll();
	int getValue();
};

