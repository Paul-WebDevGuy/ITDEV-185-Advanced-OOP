// satterlee_Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
    Paul Satterlee
    ITDEV185-900
    Assignment 1
*/

int main()
{
    string month, year;
    double amountCollected, productSales, countyTaxAmount, stateTaxAmount, totalTaxAmount;
    double STATE_TAX = 0.04;
    double COUNTY_TAX = 0.02;
    double TOTAL_TAX = 0.06;

    cout << "Please enter the month: " << endl;
    cin >> month;

    cout << "Please enter the year: " << endl;
    cin >> year;

    cout << "Enter total amount collected: " << endl;
    cin >> amountCollected;

    productSales = amountCollected / 1.06;
    countyTaxAmount = productSales * COUNTY_TAX;
    stateTaxAmount = productSales * STATE_TAX;
    totalTaxAmount = countyTaxAmount + stateTaxAmount;


    cout << "Month: " << month << " " << year << endl;
    cout << "---------------------------" << endl << endl;
    cout << fixed;
    cout << "Total collected:  $" << setw(12)<<  setprecision(2) << amountCollected << endl;
    cout << "Sales:            $" << setw(12) << setprecision(2) << productSales << endl;
    cout << "County sales tax: $" << setw(12) << setprecision(2) << countyTaxAmount << endl;
    cout << "State sales tax:  $" << setw(12) << setprecision(2) << stateTaxAmount << endl;
    cout << "Total sales tax:  $" << setw(12) << setprecision(2) << totalTaxAmount << endl;



}


