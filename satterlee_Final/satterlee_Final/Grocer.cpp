#include "Grocer.h"


/******************************************************
	         Grocer Implementation File
*******************************************************/


//Grocer constructor
Grocer::Grocer()
{

}

void Grocer::setSaleAmt(double amount)
{
	saleAmt = amount;
}

double Grocer::getSaleAmt()
{
	return saleAmt;
}

void Grocer::addItem(vector<Item*>& list, Item* item)
{
	list.push_back(item);
}

void Grocer::removeItem(vector<Item*>& list, Item item)
{
	bool isFound = false;

	for(int i = 0; i < list.size(); i++) 
	{
		if (list[i]->getName() == item.getName())
		{
			list.erase(list.begin() + i);
			isFound = true;
		}
	}

	if (!isFound)
	{
		cout << "Item is not currently available so it cannot be removed." << endl;
	}
}




