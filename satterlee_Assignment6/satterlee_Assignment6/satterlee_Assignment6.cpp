// satterlee_Assignment6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Paul Satterlee
    ITDEV185-Spring2022
    Assignment 6
*/
#include <iostream>
#include <iomanip>
#include "Player.h"

//Function Prototypes
void SetPlayerNumbers(Player array[], int size);
Player* GetHighestPlayerTotal(Player array[], int size);
void DisplayWinnerResults(Player* winner);


int main()
{
    Player player[100];                                             //Instantiate 100 player objects in an array
    const int ARRAY_BOUND = sizeof(player) / sizeof(player[0]);     //array bound control 

    SetPlayerNumbers(player, ARRAY_BOUND);
    DisplayWinnerResults(GetHighestPlayerTotal(player, ARRAY_BOUND));
}

//Function that loops through the array of Player objects and sets each player object
//to an individual number
void SetPlayerNumbers(Player array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i].SetPlayerNumber(i);
    }
}

//Function that takes in the array of Player objects and loops through to find the highest total
//of dice rolled.  Returns a pointer to the player object with the highest total
Player* GetHighestPlayerTotal(Player array[], int size)
{
    int highScore = 0;              //local variable to hold high score 
    Player* winner = nullptr;       //Player pointer initialized to null

    //loop through all players and play i.e. roll all dice and add up totals
    for (int i = 0; i < size; i++)
    {
        array[i].Play();
    }

    //find highest dice total and add high score player object address to pointer
    for (int i = 0; i < size; i++)
    {
        
        if (highScore < array[i].GetSumOfDice())
        {
            highScore = array[i].GetSumOfDice();
            winner = &array[i];
        }
    }

    return winner;
}

//Display results of highest total
void DisplayWinnerResults(Player* winner)
{
    cout << "The winning player is player" << winner->GetPlayerNumber() << " with a total of: " << winner->GetSumOfDice() << endl;
    cout << "\n\n";
    
    for (int i = 0; i < winner->GetNumOfDice(); i++)
    {
        cout << "Dice" << i << ":  " << winner->GetSingleDiceValue(i) << endl;
    }

}


