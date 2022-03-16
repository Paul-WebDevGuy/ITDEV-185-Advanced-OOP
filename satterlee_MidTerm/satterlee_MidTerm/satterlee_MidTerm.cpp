#include "Item.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

//Function declarations
void DeliveryMenu();
void MainMenu();
void FreshProductsMenu();
void MeatandSeafoodMenu();
void FrozenFoodsMenu();
void CheckOutMenu();
void DetermineFreshProductBalance(FreshProduct* item, double lbs);
void DetermineMeasuredProductBalance(MeasuredProduct* item, double num);

vector<Item*> cart;     //vector to hold item pointers for all items chosen by user

int main()
{
    DeliveryMenu();
    MainMenu();
    cart.clear();
}

//function where user will choose whether they want to pick up groceries or have them 
//delivered.  Pick up is free while delivery will incur a fee that will be added on to the
//total bill and displayed at checkout
void DeliveryMenu()
{
    int choice;         //to hold users choice for delivery or pickup
    double noTip = 0;   //for pick up
    double tip = 5;     //delivery tip amount
    double fee = 20;    //delivery fee amount


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
        Item::setTip(tip);
        break;

    case 3:
        exit(0);
    }
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

    //get user input
    switch (choice)
    {
    case 1:
        FreshProductsMenu();
        break;

    case 2:
        MeatandSeafoodMenu();
        break;

    case 3:
        FrozenFoodsMenu();
        break;

    case 4:
        CheckOutMenu();
        break;
    }
}

//fresh products menu contains items that are priced based on weight.  User will decide which
//items they want and how much in pounds.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void FreshProductsMenu()
{
    int choice;                 //to hold users choice 
    double amount;              //to hold amount chosen by user
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << "*********************************************" << endl;
    cout << "(1)  Gala Apples    $3.99/lb  " << endl;
    cout << "(2)  Bananas        $0.48/lb " << endl;
    cout << "(3)  Grapes         $2.99/lb  " << endl << endl;
    cout << "(4)  Return to Main Menu  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid input.  Please choose a valid option (1 thru 4): " << endl;
        cin >> choice;
    }

    //Each choice will ask how much of each item the user wants and then add that item 
    //to the cart.  After, the same menu will be recursively called in case the user
    //wants to add more items
    if (choice == 1)
    {
        cout << "How many pounds of apples? " << endl;
        cin >> amount;
        FreshProduct apples = FreshProduct("Gala Apples", 3.99, amount);
        DetermineFreshProductBalance(&apples, amount);
        cart.push_back(&apples);
        FreshProductsMenu();
    }

    if (choice == 2)
    {
        cout << "How many pounds of bananas? " << endl;
        cin >> amount;
        FreshProduct bananas = FreshProduct("Bananas", 0.48, amount);
        DetermineFreshProductBalance(&bananas, amount);
        cart.push_back(&bananas);
        FreshProductsMenu();
    }

    if (choice == 3)
    {
        cout << "How many pounds of grapes? " << endl;
        cin >> amount;
        FreshProduct grapes = FreshProduct("Grapes", 2.99, amount);
        DetermineFreshProductBalance(&grapes, amount);
        cart.push_back(&grapes);
        FreshProductsMenu();
    }

    //Back to main menu
    if (choice == 4)
    {
        MainMenu();
    }

 }

//meat and seafood menu contains items that are priced based on weight.  User will decide which
//items they want and how much in pounds.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void MeatandSeafoodMenu()
{
    int choice;                 //to hold users choice 
    double amount;              //to hold amount user chooses
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << "*********************************************" << endl;
    cout << "(1)  Whole Chicken  $6.99/lb  " << endl;
    cout << "(2)  Ground Beef    $4.99/lb " << endl;
    cout << "(3)  Salmon         $9.99/lb  " << endl << endl;
    cout << "(4)  Return to Main Menu  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid input.  Please choose a valid option (1 thru 4): " << endl;
        cin >> choice;
    }

    //Each choice will ask how much of each item the user wants and then add that item 
    //to the cart.  After, the same menu will be recursively called in case the user
    //wants to add more items
    if (choice == 1)
    {
        cout << "How many pounds of chicken? " << endl;
        cin >> amount;
        FreshProduct chicken = FreshProduct("Whole Chicken", 6.99, amount);
        DetermineFreshProductBalance(&chicken, amount);
        cart.push_back(&chicken);
        MeatandSeafoodMenu();
    }

    if (choice == 2)
    {
        cout << "How many pounds of ground beef? " << endl;
        cin >> amount;
        FreshProduct groundBeef = FreshProduct("Ground Beef", 4.99, amount);
        DetermineFreshProductBalance(&groundBeef, amount);
        cart.push_back(&groundBeef);
        MeatandSeafoodMenu();
    }

    if (choice == 3)
    {
        cout << "How many pounds of salmon? " << endl;
        cin >> amount;
        FreshProduct salmon = FreshProduct("Salmon", 9.99, amount);
        DetermineFreshProductBalance(&salmon, amount);
        cart.push_back(&salmon);
        MeatandSeafoodMenu();
    }

    //back to main menu
    if (choice == 4)
    {
        MainMenu();
    }
}

//frozen foods menu contains items that are priced individually.  User will decide which
//items they want and how many.  After each item is chosen an item will be instantiated
//and the amounts will be sent to the constructor
void FrozenFoodsMenu()
{
    int choice;                 //to hold users choice 
    double amount;              //to hold amount user chooses
    Item* item = nullptr;       //null item pointer

    system("cls");
    cout << "*********************************************" << endl;
    cout << "(1)  Waffles       $6.99  " << endl;
    cout << "(2)  Pizza         $4.99 " << endl;
    cout << "(3)  Popsicles     $2.99  " << endl << endl;
    cout << "(4)  Return to Main Menu  " << endl;
    cout << "*********************************************" << endl;
    cin >> choice;

    //validate input
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid input.  Please choose a valid option (1 thru 4): " << endl;
        cin >> choice;
    }

    //Each choice will ask how much of each item the user wants and then add that item 
    //to the cart.  After, the same menu will be recursively called in case the user
    //wants to add more items
    if (choice == 1)
    {
        cout << "How many packages of waffles? " << endl;
        cin >> amount;
        MeasuredProduct waffles = MeasuredProduct("Waffles", 6.99, amount);
        DetermineMeasuredProductBalance(&waffles, amount);
        cart.push_back(&waffles);
        FrozenFoodsMenu();
    }

    if (choice == 2)
    {
        cout << "How many pizzas? " << endl;
        cin >> amount;
        MeasuredProduct pizza = MeasuredProduct("Pizza", 4.99, amount);
        DetermineMeasuredProductBalance(&pizza, amount);
        cart.push_back(&pizza);
        FrozenFoodsMenu();
    }

    if (choice == 3)
    {
        cout << "How many packages of popsicles? " << endl;
        cin >> amount;
        MeasuredProduct popsicles = MeasuredProduct("Popsicles", 2.99, amount);
        DetermineMeasuredProductBalance(&popsicles, amount);
        cart.push_back(&popsicles);
        FrozenFoodsMenu();
    }

    //back to main menu
    if (choice == 4)
    {
        MainMenu();
    }
}

//Check out menu function will display each individual item in the cart, the items price, the delivery 
//fee and tip if applicable, and the total bill amount
void CheckOutMenu()
{
    system("cls");                  //clear screen to display only check out 
    int cartSize = cart.size();     //variable to hold cart size
    double total;                   //to hold total amount

    cout << fixed << showpoint << setprecision(2);
    cout << endl << endl;
    cout << "****************************************************************************" << endl;

    //loop through cart and display each item and item price
    for (int i = 0; i < cartSize; i++)
    {
        cout << left << setw(17) << cart[i]->getName() << right << setw(1) << "$ " << right << setw(10) << cart[i]->getPrice() << endl;
    }
    cout << endl << endl;

    //if delivery was chosen, display delivery fee and tip.  If delivery is not chosen, nothing will be shown here
    if (Item::getDelivery() > 0)
    {
        cout << left << setw(17) << "Tip: " << right << setw(1) << "$ " << right << setw(10) << Item::getTip() << endl;
        cout << left << setw(17) << "Delivery: " << right << setw(1) << "$ " << right << setw(10) << Item::getDelivery() << endl << endl;
    }

    //calculate total amount of bill
    total = Item::getTotalBalance() + Item::getDelivery() + Item::getTip();

    //display total amount of bill
    cout << left << setw(17) << "TOTAL: " << right << setw(1) << "$ " << right << setw(10) << total << endl ;
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


