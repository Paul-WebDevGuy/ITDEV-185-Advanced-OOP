#pragma once
#include <iostream>
#include <string>

using namespace std;


/***********************************************
	Item Class and Child Classes Header File
 ***********************************************/

class Item
{
private:
	double price = 0;
	double totalItemPrice = 0;
	double priceRate;
	double individualCost;
	string name;
	static double deliveryFee;
	static double deliveryTip;
	static double totalBalance;
	int listOrder;
	int itemIdentifier;
	int amount;
	double pounds = 0;


public:
	Item();
	static double getDelivery();
	static double getTip();
	static void setTip(double);
	static void setDelivery(double);
	static double getTotalBalance();
	void addTotalBalance(double);
	string getName();
	double getPrice();
	void setName(string);
	void setPrice(double);
	void setIndividualCost(double);
	double getIndividualCost();
	void setListOrder(int);
	int getListOrder();
	void setItemIdentifier(int);
	int getItemIdentifier();
	double getPounds();
	void setPounds(double);
	int getAmount();
	void setAmount(int);
};

/******************************************
	   FreshProducts Header Info
*******************************************/

class FreshProduct : public Item
{
public:
	FreshProduct(string, double);
	FreshProduct(string, double, double);
	void calcPrice(double, double);
};

/******************************************
	   MeasuredProducts Header Info
*******************************************/

class MeasuredProduct : public Item
{
private:
	double quantity = 0;

public:
	MeasuredProduct(string, double);
	MeasuredProduct(string, double, double);
	void calcPrice(double, double);
	double getQuantity();
	void setQuantity(double);
};

