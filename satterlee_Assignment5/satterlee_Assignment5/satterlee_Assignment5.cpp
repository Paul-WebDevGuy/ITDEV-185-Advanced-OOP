// satterlee_Assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Paul Satterlee
    ITDEV185-Spring2022
    Assignment 5
*/
#include <iostream>
#include "SlotMachine.h"
using namespace std;


int main()
{
    SlotMachine slot;       //instantiate a slot machine game
    int gameCounter = 0;    //to hold total number of times that slot machine is played

   do
    {
       gameCounter++;
       slot.play();

   } while (!slot.getGameResult());     //play game until getGameResult() returns false

   cout << endl;
   cout << gameCounter << " tries to win";
   cout << endl;
}
