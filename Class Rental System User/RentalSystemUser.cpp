#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <windows.h>
#include <vector>
#include "Car.cpp"
using namespace std;

class User
{
private:
    string userID;
    string password;
    vector<RentalHistory> rentalHistory;

public:
    User(string id = "", string pass = "") : userID(id), password(pass) {}

    void setID(string id)
    {
        userID = id;
    }

    void setPass(string pass)
    {
        password = pass;
    }

    string getID()
    {
        return userID;
    }

    string getPass()
    {
        return password;
    }

    void addRental(string carName, int days, double totalCost)
    {
        rentalHistory.push_back({carName, days, totalCost});
    }

    // Display user's rental history
    void displayRentalHistory()
    {
        if (rentalHistory.empty())
        {
            cout << "No rental history available.\n";
        }
        else
        {
            printLine();
            cout << "Rental History for " << userID << ":\n";
            for (auto &rental : rentalHistory)
            {
                cout << "Car: " << rental.carName << ", Days: " << rental.days << ", Total Cost: $" << rental.totalCost << endl;
            }
            printLine();
        }
    }
};

// Bill calculation function with discount and tax
double calculateBill(Car car, int days)
{
    double baseCost = car.price_per_day * days;
    double discount = 0;

    // Apply discount for longer rentals
    if (days >= 7)
    {
        discount = baseCost * 0.10; // 10% discount for a week or more
    }

    // Add tax and other fees
    double tax = baseCost * 0.18; // 18% tax
    double finalCost = baseCost - discount + tax;

    cout << "Base Cost: $" << baseCost << endl;
    if (discount > 0)
    {
        cout << "Discount: -$" << discount << endl;
    }
    cout << "Tax (18%): +$" << tax << endl;
    cout << "Final Cost: $" << finalCost << endl;

    return finalCost;
}