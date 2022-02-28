
#include "Coin.h"
using namespace std;

/*
    Paul Satterlee
    ITDEV185-Spring2022
    Assignment 7
*/


//evaluateToss function declaration
void evaluateToss(Coin*);

int main()
{
    Coin* coin = nullptr;       //to hold a Coin pointer variable
    Nickel nickel;              //Declare 3 different child class versions of coin class
    Dime dime;
    Quarter quarter;

    srand(time(0));

    cout << fixed << showpoint << setprecision(2);

    //loop through flipping all 3 coins per turn 
    while (Coin::getBalance() < 1)
    {
        evaluateToss(&nickel);
        evaluateToss(&dime);
        evaluateToss(&quarter);
    }

    //check if game is won or lost based on balance total
    if (Coin::getBalance() == 1)
    {
        cout << "Congrats! Your balance is exactly $1.00.  You win!";
        cout << endl;
        return 0;
    }
    else if (Coin::getBalance() > 1)
    {
        cout << "Your tosses add up to $" << Coin::getBalance() << ", so you lose.";
        cout << endl;
        return 0;
    }
}

//function that takes in a coin pointer and tosses coin.  Then, depending on what
//value that coin holds, either adds value to balance or just displays tails
void evaluateToss(Coin* coin)
{
    coin->toss();

    if (coin->getHeads())
    {
        coin->addBalance(coin->getValues());
        cout << coin->getSideUp() << "  ...$" << coin->getValues() << endl;
        cout << "Total balance: $" << coin->getBalance();
        cout << endl << endl;
    }
    else
    {
        cout << coin->getSideUp() << endl;
        cout << endl;
    }

}


