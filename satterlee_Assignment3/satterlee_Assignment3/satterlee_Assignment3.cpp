// satterlee_Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void menu();
void SpoolCharges(int spools, int stock, double specialCharges);


int main()
{
    menu();
}

void menu()
{
    int numSpools;          //to hold number of spools ordered
    int numSpoolStock;      //to hold number of spools in stock
    double specialCharge;      //to hold dollar amount of special shipping charges

    cout << "How many spools were ordered?  ";
    cin >> numSpools;

    //validate input
    if (numSpools <= 0)
    {
        cout << "Order amount must be greater than 0.  Please enter a new amount: ";
        cin >> numSpools;
    }
    cout << "How many spools are in stock?  ";
    cin >> numSpoolStock;

    //validate input
    if (numSpoolStock < 0)
    {
        cout << "In stock amount cannot be less than 0.  Please re-enter spool stock: ";
        cin >> numSpoolStock;
    }
    cout << endl;
    cout << "Amount of any special shipping charges (per spool)\n";
    cout << "above the regular $10 per spool rate(0 for none):  ";
    cin >> specialCharge;

    //validate input
    if (specialCharge < 0)
    {
        cout << "Special shipping charge cannot be less than 0.  Please enter 0 or more: ";
        cin >> specialCharge;
    }
    cout << endl;
    SpoolCharges(numSpools, numSpoolStock, specialCharge);
}

void SpoolCharges(int spools, int stock, double specialCharge)
{
    double SHIPPING_CHARGE = 10;
    double SPOOL_CHARGE = 100;
    int backOrder;                                                          //to hold amount of spools on backorder
    int spoolsInShipment = spools;                                          //to hold amount of spools in this shipment
    double spoolCharges = spools * SPOOL_CHARGE;                            //to hold spool charges
    double spoolShippingCharges = spools * SHIPPING_CHARGE;                 //to hold shipping charges
    double specialCharges = spools * specialCharge;                         //to hold special shipping charges
    double totalShippingCharges = spoolShippingCharges + specialCharges;    //to hold total shipping charges   
    double totalCharges = totalShippingCharges + spoolCharges;              //to hold total charges overall

    //determine if there is a surplus or shortage of spools
    if (spools > stock)
    {
        spoolsInShipment = stock;
        backOrder = spools - stock;
        spoolCharges = spoolsInShipment * SPOOL_CHARGE;
        specialCharges = spoolsInShipment * specialCharge;
        spoolShippingCharges = spoolsInShipment * SHIPPING_CHARGE;
        totalShippingCharges = specialCharges + spoolShippingCharges;
        totalCharges = spoolCharges + totalShippingCharges;
    }
    else
    {
        spoolsInShipment = spools;
    }

    //Display shipment and spool info
    cout << setw(30) << "*** Order Summary ***";
    cout << endl;
    cout << left << setw(25) << "Spools ordered: " << right << setw(10) << spools << endl;
    cout << left << setw(25) << "Spools in this shipment: " << right  << setw(10) << spoolsInShipment << endl;

    //Display backorder info only if necessary
    if (spools > stock)
    {
        cout << left << setw(25) << "Spools backordered: " << right << setw(10) << backOrder << endl;
    }
    cout << endl;
    
    //Display shipping information
    cout << setw(30) <<"Charges for this shipment" << endl;
    cout << setw(30) << "--------------------------------------" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << left << setw(25) <<"Spool charges: " << right << setw(1) << "$ " << right << setw(10) << spoolCharges << endl;
    cout << left << setw(25) << "Shipping charges: " << right << setw(1) << "$ " << right << setw(10) << totalShippingCharges << endl;
    cout << left << setw(25) << "Total this shipment: " << right << setw(1) << "$ " << right << setw(10) << totalCharges << endl;

}


