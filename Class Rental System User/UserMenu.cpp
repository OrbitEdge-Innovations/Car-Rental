#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <windows.h>
#include <vector>
#include "RentalSystemUser.cpp"
using namespace std;

class UserMenu
{
    void userMenu(User &user, Showroom &showroom)
    {
        int choice;
        string carName;
        int days;
        double totalCost;

        while (true)
        {
            cout << "\nUser Menu:\n";
            cout << "1. View available cars\n";
            cout << "2. Rent a car\n";
            cout << "3. Return a car\n";
            cout << "4. View rental history\n";
            cout << "5. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            try
            {
                if (choice == 1)
                {
                    showroom.displayCars();
                }
                else if (choice == 2)
                {
                    cout << "Enter the name of the car you want to rent: ";
                    cin >> carName;
                    cout << "Enter the number of days you want to rent it for: ";
                    cin >> days;
                    Car rentedCar = showroom.rentCar(carName);
                    totalCost = calculateBill(rentedCar, days);
                    user.addRental(carName, days, totalCost);
                    cout << "Car rented successfully. Total cost: $" << totalCost << endl;
                }
                else if (choice == 3)
                {
                    cout << "Enter the name of the car you want to return: ";
                    cin >> carName;
                    showroom.returnCar(carName);
                    cout << "Car returned successfully!\n";
                }
                else if (choice == 4)
                {
                    user.displayRentalHistory();
                }
                else if (choice == 5)
                {
                    break; // Logout
                }
                else
                {
                    cout << "Invalid choice, please try again.\n";
                }
            }
            catch (const runtime_error &e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
    }
};
