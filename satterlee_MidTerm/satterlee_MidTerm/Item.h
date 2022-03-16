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
	string name;
	static double deliveryFee;
	static double deliveryTip;
	static double totalBalance;


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
};

/******************************************
	   FreshProducts Header Info
*******************************************/

class FreshProduct : public Item
{
private:
	double pounds = 0;

public:
	FreshProduct(string, double, double);
	void calcPrice(double, double);
	double getPounds();
	void setPounds(double);

};

/******************************************
	   MeasuredProducts Header Info
*******************************************/

class MeasuredProduct : public Item
{
private:
	double quantity = 0;

public:
	MeasuredProduct(string, double, double);
	void calcPrice(double, double);
	double getQuantity();
	void setQuantity(double);
};

