//Paul Satterlee
//ITDEV185-Spring2022
//Final Project

#include "Item.h"
#include "Grocer.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

//Function declarations
void StartMenu();
void GrocerMenu();
void FrozenFoodItemEntry();
void ProduceFoodItemEntry();
void MeatandSeafoodItemEntry();
void DeliveryMenu();
double GetTipAmount();
void MainMenu();
void FreshProductsMenu();
void MeatandSeafoodMenu();
void FrozenFoodsMenu();
void CheckOutMenu();
void DetermineFreshProductBalance(FreshProduct* item, double lbs);
void DetermineMeasuredProductBalance(MeasuredProduct* item, double num);

vector<Item*> cart;                 //vector to hold item pointers for all items chosen by user
vector<Item> FrozenFoodsList;
vector<Item> FreshProduceList;
vector<Item> MeatandSeafoodList;

int main()
{
    StartMenu();
    MainMenu();
    cart.clear();
}

/*First menu user will see.From here they can enter into the Grocer Menu which allows them to populate
* each individual grocery menu.  In an more robust application, this would come with some login credentials
* but here it can be accessed by anyone.*/

void StartMenu()
{
    int choice;         //to hold user choice

    cout << "*********************************************" << endl;
    cout << "(1)  Grocer Menu  " << endl;
    cout << "(2)  Customer Menu " << endl << endl;
    cout << "(3)  Exit  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid selection.  Please choose 1, 2, or 3:  " << endl;
        cin >> choice;
    }

    switch (choice)
    {
    case 1:
        GrocerMenu();
        break;

    case 2:
        DeliveryMenu();
        break;

    case 3:
        exit(0);
    }
}

/*
    Grocer menu is where users will be able to enter in items and item prices.  Each item will be placed 
    in one of three categories.  From here, after populating grocery menus, the user can then go to
    the customer menu
*/
void GrocerMenu()
{
    int choice;         //to hold user choice

    system("cls");
    cout << "************************************************************************" << endl << endl;
    cout << "                    WELCOME TO THE GROCER MENU!" << endl;
    cout << "You will be entering info about products that will be for sale " << endl;
    cout << "at your grocery store.  If you are not a grocer, please exit or return" << endl;
    cout << "to start menu.  Thank you" << endl << endl;
    cout << "************************************************************************" << endl << endl << endl;
    cout << "Please select a department to input grocery item information: " << endl;
    cout << "(1)  Produce  " << endl;
    cout << "(2)  Meat and Seafood " << endl;
    cout << "(3)  Frozen Foods " << endl;
    cout << "(4)  Customer Menu " << endl << endl;
    cout << "(5)  Exit  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid selection.  Please choose 1, 2, 3, 4, or 5:  " << endl;
        cin >> choice;
    }

    if (choice == 1)
    {
        ProduceFoodItemEntry();
    }

    if (choice == 2)
    {
        MeatandSeafoodItemEntry();
    }

    if (choice == 3)
    {
        FrozenFoodItemEntry();
    }

    if (choice == 4)
    {
        DeliveryMenu();
    }

    if (choice == 5)
    {
        exit(0);
    }

}

/*Function where user can enter information about available Frozen food items.  Each item will get a name
and a price.  After entering a name and price, the user will have the option to add more items, delete the 
last item entered, or return to the previous menu (Grocer menu).  After the user has entered the info needed,
the item will be instantiated and the item object will be added to a vector containing objects of the same type*/

void FrozenFoodItemEntry()
{
    string itemName;            //to hold item name
    int continueChoice;         //to hold choice of what user wants to do after initial choice
    double itemPrice;           //to hold item price

    system("cls");
    cout << "Name of Frozen Foods item:" << endl;
    cin.ignore(1, '\n');
    getline(cin, itemName);
    cout << "Price of Frozen Foods item:" << endl;
    cin >> itemPrice;

    //validate input
    while (itemPrice < 0)
    {
        cout << "Invalid item price.  Please enter a price greater than zero:  ";
        cin >> itemPrice;
    }

    MeasuredProduct frozen = MeasuredProduct(itemName, itemPrice);      //instantiate frozen food object
    FrozenFoodsList.push_back(frozen);                                  //add object to FrozenFoodsList vector

    system("cls");
    cout << "**********************************************" << endl;
    cout << "(1)  Add another Frozen Foods item " << endl;
    cout << "(2)  Remove previous item" << endl;
    cout << "(3)  Return to previous menu" << endl << endl;
    cout << "**********************************************" << endl;
    cin >> continueChoice;

    //validate input
    while (continueChoice < 1 || continueChoice > 3)
    {
        cout << "Invalid input.  Please enter 1, 2, or 3:  ";
        cin >> continueChoice;
    }

    if (continueChoice == 1)
    {
        FrozenFoodItemEntry();
    }

    if (continueChoice == 2)
    {
        FrozenFoodsList.pop_back();                                 //remove last item in vector
        cout << "Last item entered has been removed." << endl;
        FrozenFoodItemEntry();
    }

    if (continueChoice == 3)
    {
        GrocerMenu();
    }
}

/*Essentially the same function as the frozen food function above.  However, this function takes in a price
per pound instead of a price per item.*/
void ProduceFoodItemEntry()
{
    string itemName;            //to hold item name
    int continueChoice;         //to hold choice after user enters intital info
    double itemPrice;           //to hold item price

    system("cls");
    cout << "Name of Produce Food item:  " << endl;
    cin.ignore(1, '\n');
    getline(cin, itemName);
    cout << endl;
    cout << "Price per pound of Produce Food item: " << endl;
    cin >> itemPrice;

    //validate input
    while (itemPrice < 0)
    {
        cout << "Invalid item price.  Please enter a price greater than zero:  ";
        cin >> itemPrice;
    }

    FreshProduct produceItem = FreshProduct(itemName, itemPrice);       //instantiate object
    FreshProduceList.push_back(produceItem);                            //add object to fresh produce list vector

    system("cls");
    cout << "**********************************************" << endl;
    cout << "(1)  Add another Produce Food item " << endl;
    cout << "(2)  Remove previous item" << endl;
    cout << "(3)  Return to previous menu" << endl << endl;
    cout << "**********************************************" << endl;
    cin >> continueChoice;

    //validate input
    while (continueChoice < 1 || continueChoice > 3)
    {
        cout << "Invalid input.  Please enter 1, 2, or 3:  ";
        cin >> continueChoice;
    }

    if (continueChoice == 1)
    {
        ProduceFoodItemEntry();
    }

    if (continueChoice == 2)
    {
        FreshProduceList.pop_back();                                //remove last item in vector
        cout << "Last item entered has been removed." << endl;
        ProduceFoodItemEntry();
    }

    if (continueChoice == 3)
    {
        GrocerMenu();
    }
}

//Same function and logic as above Fresh Produce function
void MeatandSeafoodItemEntry()
{
    string itemName;
    int continueChoice;
    double itemPrice;

    system("cls");
    cout << "Name of Meat or Seafood item:  " << endl;
    cin.ignore(1, '\n');
    getline(cin, itemName);
    cout << endl;
    cout << "Price per pound of Meat or Seafood item: " << endl;
    cin >> itemPrice;

    //validate input
    while (itemPrice < 0)
    {
        cout << "Invalid item price.  Please enter a price greater than zero:  ";
        cin >> itemPrice;
    }

    FreshProduct meatSeafoodItem = FreshProduct(itemName, itemPrice);       //instantiate object
    MeatandSeafoodList.push_back(meatSeafoodItem);                          //add object to meat and seafood vector

    system("cls");
    cout << "**********************************************" << endl;
    cout << "(1)  Add another Meat and seafood item " << endl;
    cout << "(2)  Remove previous item" << endl;
    cout << "(3)  Return to previous menu" << endl << endl;
    cout << "**********************************************" << endl;
    cin >> continueChoice;

    //validate input
    while (continueChoice < 1 || continueChoice > 3)
    {
        cout << "Invalid input.  Please enter 1, 2, or 3:  ";
        cin >> continueChoice;
    }

    if (continueChoice == 1)
    {
        MeatandSeafoodItemEntry();
    }

    if (continueChoice == 2)
    {
        MeatandSeafoodList.pop_back();                          //remove last item entered into vector
        cout << "Last item entered has been removed." << endl;
        MeatandSeafoodItemEntry();
    }

    if (continueChoice == 3)
    {
        GrocerMenu();
    }
}

//function where user will choose whether they want to pick up groceries or have them 
//delivered.  Pick up is free while delivery will incur a fee that will be added on to the
//total bill and displayed at checkout
void DeliveryMenu()
{
    int choice;         //to hold users choice for delivery or pickup
    double noTip = 0;   //for pick up
    double fee = 20;    //delivery fee amount

    system("cls");
    cout << "*********************************************" << endl;
    cout << "(1)  Pick-Up  " << endl;
    cout << "(2)  Delivery " << endl << endl;
    cout << "(3)  Exit  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid selection.  Please choose 1, 2, or 3:  " << endl;
        cin >> choice;
    }

    //determine what user wants to do for retrieving groceries
    switch (choice)
    {
    case 1:
        Item::setDelivery(noTip);
        Item::setTip(noTip);
        break;

    case 2:
        Item::setDelivery(fee);
        Item::setTip(GetTipAmount());
        break;

    case 3:
        exit(0);
    }
}

//Get percentage amount that customer would like to tip their delivery driver
double GetTipAmount()
{
    double tipAmount;

    cout << "What percentage would you like to tip? ";
    cin >> tipAmount;

    while (tipAmount <= 0)      //if delivery is chosen, must tip more than zero
    {
        cout << endl;
        cout << "Cannot tip a negative amount or tip only zero.  Please enter a valid tip amount: ";
        cin >> tipAmount;
    }

    while (tipAmount > 100)     
    {
        cout << endl;
        cout << "That's very generous of you, but you cannot tip greater than 100%." << endl;
        cout << "Please enter a valid tip amount: ";
        cin >> tipAmount;
    }

    return tipAmount;
}

//main menu will display 3 different grocery departments and a checkout option.  
//The user will decide which department to go to or if they want to pay for their groceries
void MainMenu()
{
    int choice;         //to hold users choice of item

    system("cls");
    cout << "*********************************************" << endl;
    cout << "(1)  Fresh Products  " << endl;
    cout << "(2)  Meat and Seafood " << endl;
    cout << "(3)  Frozen Foods  " << endl << endl;
    cout << "(4)  Check Out  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid selection.  Please choose 1, 2, 3 or 4:  " << endl;
        cin >> choice;
    }

    if (choice == 1)
    {
        FreshProductsMenu();
    }

    if (choice == 2)
    {
        MeatandSeafoodMenu();
    }

    if (choice == 3)
    {
        FrozenFoodsMenu();
    }

    if (choice == 4)
    {
        CheckOutMenu();
    }
}

//fresh products menu contains items that are priced based on weight.  User will decide which
//items they want and how much in pounds.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void FreshProductsMenu()
{
    int choice;                 //to hold users choice 
    int returnChoice;
    double amount;              //to hold amount chosen by user
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << fixed << showpoint << setprecision(2);
    cout << "*********************************************" << endl;
    
    //If no items have been entered by grocer, customer will see this message
    if (FreshProduceList.empty() == true)
    {
        cout << "No Fresh Produce items are currently available.  Please check back later." << endl;
        cout << "Press (1) to return to Main Menu." << endl;
        cin >> returnChoice;

        //validate input
        while (returnChoice != 1)
        {
            cout << "Invalid input.  Please enter (1) to return to Main Menu." << endl;
            cin >> returnChoice;
        }

        if (returnChoice == 1)
        {
            MainMenu();
        }
    }

    //Display all items that grocer has added to department list vector
    for (int i = 0; i < FreshProduceList.size(); ++i)
    {
        FreshProduceList[i].setListOrder(i + 1);
        cout << left << "(" << i + 1 << ")  " << setw(15) << FreshProduceList[i].getName() 
            << right << setw(1) << "$ " << right << setw(10) << FreshProduceList[i].getIndividualCost() << endl;
    }

    //If there are items in the vector, this will be displayed
    if (FreshProduceList.empty() == false)
    {
        cout << endl;
        cout << left <<  "(" << FreshProduceList.size() + 1 << ")  " <<  "Return to Main Menu" << endl << endl;
    }
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > FreshProduceList.size() + 1)
    {
        cout << "Invalid input.  Please choose a valid option: " << endl;
        cin >> choice;
    }

    //Return to Main Menu option will always be one more than the total number of items available
    if (choice == FreshProduceList.size() + 1)
    {
        MainMenu();
    }

    //As customer chooses products, add them to cart and determine balance
    for (int i = 0; i < FreshProduceList.size(); ++i)
    {
        if (choice == FreshProduceList[i].getListOrder())
        {
            cout << "Amount in lbs: ";
            cin >> amount;
            FreshProduct newProduct = FreshProduct(FreshProduceList[i].getName(), FreshProduceList[i].getIndividualCost(), amount);
            DetermineFreshProductBalance(&newProduct, amount);
            cart.push_back(&newProduct);
            FreshProductsMenu();
        }
    }
}

//meat and seafood menu contains items that are priced based on weight.  User will decide which
//items they want and how much in pounds.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void MeatandSeafoodMenu()
{
    int choice;                 //to hold users choice 
    int returnChoice;
    double amount;              //to hold amount chosen by user
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << fixed << showpoint << setprecision(2);
    cout << "*********************************************" << endl;

    //Display if list is empty
    if (MeatandSeafoodList.empty() == true)
    {
        cout << "No Meat and Seafood items are currently available.  Please check back later." << endl;
        cout << "Press (1) to return to Main Menu." << endl;
        cin >> returnChoice;

        //validate input
        while (returnChoice != 1)
        {
            cout << "Invalid input.  Please enter (1) to return to Main Menu." << endl;
            cin >> returnChoice;
        }

        if (returnChoice == 1)
        {
            MainMenu();
        }
    }

    //Display list of items that were input by the grocer
    for (int i = 0; i < MeatandSeafoodList.size(); i++)
    {
        MeatandSeafoodList[i].setListOrder(i + 1);
        cout << left << "(" << i + 1 << ")  " << setw(15) << MeatandSeafoodList[i].getName() 
            << right << setw(1) << "$ " << right << setw(10) << MeatandSeafoodList[i].getIndividualCost() << endl;
    }

    if (MeatandSeafoodList.empty() == false)
    {
        cout << endl;
        cout << left << "(" << MeatandSeafoodList.size() + 1 << ")  " << "Return to Main Menu" << endl << endl;
    }
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > MeatandSeafoodList.size() + 1)
    {
        cout << "Invalid input.  Please choose a valid option: " << endl;
        cin >> choice;
    }

    //Return to main menu option will always be one more than the size of the vector
    if (choice == MeatandSeafoodList.size() + 1)
    {
        MainMenu();
    }

    //Add items chosen by customer to cart and determine balance
    for (int i = 0; i < MeatandSeafoodList.size(); i++)
    {
        if (choice == MeatandSeafoodList[i].getListOrder())
        {
            cout << "Amount in lbs: ";
            cin >> amount;
            FreshProduct newProduct = FreshProduct(MeatandSeafoodList[i].getName(), MeatandSeafoodList[i].getIndividualCost(), amount);
            DetermineFreshProductBalance(&newProduct, amount);
            cart.push_back(&newProduct);
            MeatandSeafoodMenu();
        }
    }
}

//frozen foods menu contains items that are priced individually.  User will decide which
//items they want and how many.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void FrozenFoodsMenu()
{
    int choice;                 //to hold users choice 
    int returnChoice;
    double amount;              //to hold amount chosen by user
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << fixed << showpoint << setprecision(2);
    cout << "*********************************************" << endl;

    //Display if list is empty
    if (FrozenFoodsList.empty() == true)
    {
        cout << "No Frozen food items are currently available.  Please check back later." << endl;
        cout << "Press (1) to return to Main Menu." << endl;
        cin >> returnChoice;

        //validate input
        while (returnChoice != 1)
        {
            cout << "Invalid input.  Please enter (1) to return to Main Menu." << endl;
            cin >> returnChoice;
        }

        if (returnChoice == 1)
        {
            MainMenu();
        }
    }

    //display list of items created by grocer
    for (int i = 0; i < FrozenFoodsList.size(); i++)
    {
        FrozenFoodsList[i].setListOrder(i + 1);
        cout << left << "(" << i + 1 << ")  " << setw(15) << FrozenFoodsList[i].getName() 
            << right << setw(1) << "$ " << right << setw(10) << FrozenFoodsList[i].getIndividualCost() << endl;
    }

    if (FrozenFoodsList.empty() == false)
    {
        cout << endl;
        cout << left << "(" << FrozenFoodsList.size() + 1 << ")  " << "Return to Main Menu" << endl << endl;
    }
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > FrozenFoodsList.size() + 1)
    {
        cout << "Invalid input.  Please choose a valid option: " << endl;
        cin >> choice;
    }

    if (choice == FrozenFoodsList.size() + 1)
    {
        MainMenu();
    }

    //Add items to cart as chosen by customer
    for (int i = 0; i < FrozenFoodsList.size(); i++)
    {
        if (choice == FrozenFoodsList[i].getListOrder())
        {
            cout << "Amount: ";
            cin >> amount;
            MeasuredProduct newProduct = MeasuredProduct(FrozenFoodsList[i].getName(), FrozenFoodsList[i].getIndividualCost(), amount);
            DetermineMeasuredProductBalance(&newProduct, amount);
            cart.push_back(&newProduct);
            FrozenFoodsMenu();
        }
    }
}

//Check out menu function will display each individual item in the cart, the items price, the delivery 
//fee and tip if applicable, and the total bill amount
void CheckOutMenu()
{
    system("cls");                                                              //clear screen to display only check out 
    int cartSize = cart.size();                                                 //variable to hold cart size
    double total;                                                               //to hold total amount
    double totalTipAmt = Item::getTip() * Item::getTotalBalance();             //to hold tip amount

    cout << fixed << showpoint << setprecision(2);
    cout << endl << endl;
    cout << "****************************************************************************" << endl;

    //loop through cart and display each item and item price
    for (int i = 0; i < cartSize; i++)
    {
        //itemIdentifier 1 is for products purchased based on weight
        if (cart[i]->getItemIdentifier() == 1)
        {
            cout << left << setw(17) << cart[i]->getName() << left << setw(5) << cart[i]->getPounds() << "lbs  " 
                 << "@ $" << cart[i]->getIndividualCost() << "/lb  "
                 << right << setw(3) << "$ " << right << setw(10) << cart[i]->getPrice() << endl;
        }

        //itemIdentifier 2 is for products purchased individually
        if (cart[i]->getItemIdentifier() == 2)
        {
            cout << left << setw(17) << cart[i]->getName() << left << setw(10) << cart[i]->getAmount() << "@ $"
                << cart[i]->getIndividualCost() << " each" << right << setw(3) << "$ " << right << setw(10) << cart[i]->getPrice() << endl;
        }
    }
    cout << endl << endl;

    //if delivery was chosen, display delivery fee and tip.  If delivery is not chosen, nothing will be shown here
    if (Item::getDelivery() > 0)
    {
        cout << left << setw(17) << "Tip: " << right << setw(1) << "$ " << right << setw(10) << totalTipAmt << endl;
        cout << left << setw(17) << "Delivery Fee: " << right << setw(1) << "$ " << right << setw(10) << Item::getDelivery() << endl << endl;
    }

    //calculate total amount of bill
    total = Item::getTotalBalance() + Item::getDelivery() + totalTipAmt;

    //display total amount of bill
    cout << left << setw(17) << "TOTAL: " << right << setw(1) << "$ " << right << setw(10) << total << endl;
    cout << "***************************************************************************" << endl << endl;
}

//function to add amounts to static member variable totalBalance
//This function accepts a FreshProduct item pointer parameter
void DetermineFreshProductBalance(FreshProduct* item, double lbs)
{
    item->setPounds(lbs);
    item->addTotalBalance(item->getPrice());
}

//function to add amounts to static member variable totalBalance
//This function accepts a MeasuredProduct item pointer variable
void DetermineMeasuredProductBalance(MeasuredProduct* item, double num)
{
    item->setQuantity(num);
    item->addTotalBalance(item->getPrice());
}
