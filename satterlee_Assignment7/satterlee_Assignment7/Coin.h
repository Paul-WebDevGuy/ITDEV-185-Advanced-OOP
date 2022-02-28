#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

/***********************************************
	Coin Class and Child Class Header File
 ***********************************************/
class Coin
{
protected:
	static double balance;
	string sideUp;
	bool heads;
	double value;

public:
	Coin();
	void addBalance(double v);
	static double getBalance();
	void toss();
	bool getHeads();
	double getValues();
	string getSideUp();
};

class Nickel : public Coin
{
public:
	Nickel();
};

class Dime : public Coin
{
public:
	Dime();
};

class Quarter : public Coin
{
public:
	Quarter();
};

