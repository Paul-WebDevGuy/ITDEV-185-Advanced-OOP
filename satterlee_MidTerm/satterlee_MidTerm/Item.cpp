#include "Item.h"

/******************************************************
	Item Class and Child Class Implementation File
*******************************************************/


double Item::deliveryFee = 0;		//initialize delivery fee to zero in static member variable
double Item::deliveryTip = 0;		//initialize delivery tip to zero in static member variable
double Item::totalBalance = 0;

//Item constructor
Item::Item()
{

}

//returns delivery fee amount
double Item::getDelivery()
{
	return deliveryFee;
}

//returns delivery tip amount
double Item::getTip()
{
	return deliveryTip;
}

//set tip amount
void Item::setTip(double tip)
{
	deliveryTip = tip;
}

//set delivery fee amount
void Item::setDelivery(double tip)
{
	deliveryFee = tip;
}

//add price of individual items to total balance
//totalBalance is a static parent class member
void Item::addTotalBalance(double v)
{
	totalBalance += v;
}

//returns static member variable totalBalance amount
double Item::getTotalBalance()
{
	return totalBalance;
}

//returns name of item
string Item::getName()
{
	return name;
}

//set name of item
void Item::setName(string x)
{
	name = x;
}

//get price of item
double Item::getPrice()
{
	return price;
}

//set price of item
void Item::setPrice(double cost)
{
	price = cost;
}

//FreshProduct constructor
FreshProduct::FreshProduct(string itemName, double cost, double amount)
{
	setName(itemName);
	calcPrice(cost, amount);
}

//calculate price function takes in two parameters and determines total cost of 
//FreshProduct item based on weight and cost
void FreshProduct::calcPrice(double cost, double amount)
{
	double totalItemPrice;

	totalItemPrice = cost * amount;

	setPrice(totalItemPrice);
}

//returns pound amount
double FreshProduct::getPounds()
{
	return pounds;
}

//sets pound amount
void FreshProduct::setPounds(double lbs)
{
	pounds = lbs;
}

//MeasuredProduct constructor
MeasuredProduct::MeasuredProduct(string itemName, double cost, double amount)
{
	setName(itemName);
	calcPrice(cost, amount);
}

//calculate price function takes in two parameters and determines total cost of
//item based on cost and amount chosen by user
void MeasuredProduct::calcPrice(double cost, double amount)
{
	double totalItemPrice;

	totalItemPrice = cost * amount;

	setPrice(totalItemPrice);
}

//returns quantity amount
double MeasuredProduct::getQuantity()
{
	return quantity;
}

//sets quantity amount
void MeasuredProduct::setQuantity(double amount)
{
	quantity = amount;
}