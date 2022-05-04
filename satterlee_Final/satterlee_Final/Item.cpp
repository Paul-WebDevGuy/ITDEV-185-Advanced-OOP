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
	double tipPercent = tip * .01;
	deliveryTip = tipPercent;
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

//returns individual cost of item
double Item::getIndividualCost()
{
	return individualCost;
}

//sets individual cost
void Item::setIndividualCost(double cost)
{
	individualCost = cost;
}

//sets list order as items are added by grocer
void Item::setListOrder(int order)
{
	listOrder = order;
}

//returns list order
int Item::getListOrder()
{
	return listOrder;
}

//item identifier keeps track of items based on if they are purchased
//by the pound or individually.  This allows for different output at checkout
//based on whichever type of purchase the item is
void Item::setItemIdentifier(int num)
{
	itemIdentifier = num;
}

//return item identifier 
int Item::getItemIdentifier()
{
	return itemIdentifier;
}

//returns pound amount
double Item::getPounds()
{
	return pounds;
}

//sets pound amount
void Item::setPounds(double lbs)
{
	pounds = lbs;
}

//number of items chosen by customer 
void Item::setAmount(int num)
{
	amount = num;
}

//get item amount
int Item::getAmount()
{
	return amount;
}

//FreshProduct constructor for Grocer when constructing the available grocery list
FreshProduct::FreshProduct(string itemName, double cost)
{
	setName(itemName);
	setIndividualCost(cost);
}

//FreshProduct constructor for users when choosing groceries
FreshProduct::FreshProduct(string itemName, double cost, double amount)
{
	setName(itemName);
	calcPrice(cost, amount);
	setPounds(amount);
	setIndividualCost(cost);
	setItemIdentifier(1);
}

//calculate price function takes in two parameters and determines total cost of 
//FreshProduct item based on weight and cost
void FreshProduct::calcPrice(double cost, double amount)
{
	double totalItemPrice;

	totalItemPrice = cost * amount;

	setPrice(totalItemPrice);
}

//Measured Product constructor for Grocer when constructing the available grocery list
MeasuredProduct::MeasuredProduct(string itemName, double cost)
{
	setName(itemName);
	setIndividualCost(cost);
}

//MeasuredProduct constructor
MeasuredProduct::MeasuredProduct(string itemName, double cost, double amount)
{
	setName(itemName);
	calcPrice(cost, amount);
	setAmount(amount);
	setIndividualCost(cost);
	setItemIdentifier(2);
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