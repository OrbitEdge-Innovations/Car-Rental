#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <windows.h>
#include <vector>
#include "ShowRoom.cpp"
using namespace std;

class AdminMenu
{
    void adminMenu(Showroom &showroom)
    {
        int choice;
        string carName;
        double price;
        int quantity;
        string fuelType;
        string transmission;
        int seatingCapacity;

        while (true)
        {
            cout << "\nAdmin Menu:\n";
            cout << "1. View available cars\n";
            cout << "2. Add a new car\n";
            cout << "3. Edit a car\n";
            cout << "4. Remove a car\n";
            cout << "5. View most rented cars\n";
            cout << "6. Logout\n";
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
                    cout << "Enter car name: ";
                    cin >> carName;
                    cout << "Enter price per day: ";
                    cin >> price;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    cout << "Enter fuel type: ";
                    cin >> fuelType;
                    cout << "Enter transmission type: ";
                    cin >> transmission;
                    cout << "Enter seating capacity: ";
                    cin >> seatingCapacity;
                    showroom.addCar(carName, price, quantity, fuelType, transmission, seatingCapacity);
                }
                else if (choice == 3)
                {
                    cout << "Enter car name to edit: ";
                    cin >> carName;
                    cout << "Enter new price per day: ";
                    cin >> price;
                    cout << "Enter new quantity: ";
                    cin >> quantity;
                    cout << "Enter new fuel type: ";
                    cin >> fuelType;
                    cout << "Enter new transmission type: ";
                    cin >> transmission;
                    cout << "Enter new seating capacity: ";
                    cin >> seatingCapacity;
                    showroom.editCar(carName, price, quantity, fuelType, transmission, seatingCapacity);
                }
                else if (choice == 4)
                {
                    cout << "Enter car name to remove: ";
                    cin >> carName;
                    showroom.removeCar(carName);
                }
                else if (choice == 5)
                {
                    showroom.displayMostRentedCars();
                }
                else if (choice == 6)
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