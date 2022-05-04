#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"

using namespace std;

/***********************************************
	       Grocer Class Header File
 ***********************************************/

class Grocer
{
private:
	double saleAmt;				//to hold sale amount determined by grocer

public:
	Grocer();
	void setSaleAmt(double);
	double getSaleAmt();
	void addItem(vector<Item*>&, Item*);
	void removeItem(vector<Item*>&, Item);
};

