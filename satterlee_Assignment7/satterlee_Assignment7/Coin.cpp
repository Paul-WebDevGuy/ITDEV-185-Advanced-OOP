#include "Coin.h"

/*****************************************************
    Coin Class and Child Class Implementation File
******************************************************/


double Coin::balance = 0;       //initialize static balance variable to zero

//base class constructor.  Flips the coin
Coin::Coin()
{
    int flipResult;

    flipResult = (rand() % 2) + 1;
    if (flipResult == 1)
    {
        sideUp = "HEADS";
        heads = true;
    }
    else
    {
        sideUp = "tails";
        heads = false;
    }
}

//takes in a value and adds it to balance
void Coin::addBalance(double v)
{
    balance += v;
}

//returns static balance value
double Coin::getBalance()
{
    return balance;
}

//toss function flips a coin and sets sideUp to either heads or tails
void Coin::toss()
{
    int flip;

    flip = (rand() % 2) + 1;
    if (flip == 1)
    {
        sideUp = "HEADS";
        heads = true;
    }
    else
    {
        sideUp = "tails";
        heads = false;
    }
}

//returns true if heads is up, false if heads is down
bool Coin::getHeads()
{
    return heads;
}

//returns value of coin
double Coin::getValues()
{
    return value;
}

//returns side up of coin that has been tossed
string Coin::getSideUp()
{
    return sideUp;
}

//Nickel child class constructor
Nickel::Nickel()
{
    value = 0.05;
}

//dime child class constructor
Dime::Dime()
{
    value = 0.1;
}

//quarter child class constructor
Quarter::Quarter()
{
    value = 0.25;
}