
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;


//Coin class declaration
class Coin
{
private:
    string sideUp;          //will hold either HEADS or tails, depending on result of coin flip
    bool heads = false;     //true if heads is up, false if tails
    double value;           //to hold decimal value if coin

public:                     //member function prototypes
    Coin(double v);
    void toss();
    bool getHeads();
    double getValues();
    string getSideUp();
};

//Coin member function implementation section

/**
    Coin::Coin
    This is the constructor function.  It will take in a decimal and assign that number to value.
    It also randomly decides which side of the coin is up on the initial flip.
**/
Coin::Coin(double v)
{
    int flipResult;
    value = v;

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

/**
    Coin::toss
    This function randomly decides whether a coin flip results in heads or tails
**/
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

/**
    Coin::getHeads
    This function returns the value of the "heads" variable
**/
bool Coin::getHeads()
{
    return heads;
}

/**
    Coin::getValue
    This function returns the value of the coin that is flipped
**/
double Coin::getValues()
{
    return value;
}

/**
    Coin::getSideUp
    This function returns the value of the variable sideUp
**/
string Coin::getSideUp()
{
    return sideUp;
}


int main()
{
    Coin nickel = Coin(0.05);       //instantiate 3 coin objects, one for each type of coin
    Coin dime = Coin(0.10);
    Coin quarter = Coin(0.25);
    
    double balance = 0;             //to hold total balance during game
    srand(time(0));

    cout << fixed << showpoint << setprecision(2);

    while (balance < 1)
    {
        //toss all 3 coins
        nickel.toss();
        dime.toss();
        quarter.toss();

        //check the nickel for side up and add value to the balance
        if (nickel.getHeads())
        {
            balance += nickel.getValues();
            cout << nickel.getSideUp() << "  ...$" << nickel.getValues() << endl;
            cout << "Total balance: $" << balance;
            cout << endl << endl;
        }
        else
        {
            cout << nickel.getSideUp() << endl;
            cout << endl;
        }

        //check the dime for side up and add value to the balance
        if (dime.getHeads())
        {
            balance += dime.getValues();
            cout << dime.getSideUp() << "  ...$" << dime.getValues() << endl;
            cout << "Total balance: $" << balance;
            cout << endl << endl;
        }
        else
        {
            cout << dime.getSideUp() << endl;
            cout << endl;
        }

        //check the quarter for side up and add value to the balance
        if (quarter.getHeads())
        {
            balance += quarter.getValues();
            cout << quarter.getSideUp() << "  ...$" << quarter.getValues() << endl;
            cout << "Total balance: $" << balance;
            cout << endl << endl;
        }
        else
        {
            cout << quarter.getSideUp() << endl;
            cout << endl;
        }
    }

    //check if balance equals exactly $1, or if balance is more than $1
    if (balance == 1)
    {
        cout << "Congrats! Your balance is exactly $1.00.  You win!";
        cout << endl;
        return 0;
    }
    else if (balance > 1)
    {
        cout << "Your tosses add up to $" << balance << ", so you lose.";
        cout << endl;
        return 0;
    }
}



