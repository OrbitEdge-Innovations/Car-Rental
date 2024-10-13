#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <windows.h>
#include <vector>
#include "Car.cpp"
using namespace std;

class Showroom
{
private:
    map<string, Car> cars; // Storing cars by name for quick access

public:
    Showroom()
    {
        // Example cars in the showroom for testing
        cars["Sedan"] = Car("Sedan", 50, 5, "Petrol", "Automatic", 5);
        cars["SUV"] = Car("SUV", 80, 3, "Diesel", "Manual", 7);
        cars["Hatchback"] = Car("Hatchback", 40, 7, "Petrol", "Automatic", 5);
    }

    // Display cars with detailed information
    void displayCars()
    {
        printLine();
        cout << "Available Cars in Showroom:\n";
        for (auto &car : cars)
        {
            cout << "Car: " << car.second.name << ", Price/Day: $" << car.second.price_per_day
                 << ", Quantity: " << car.second.quantity << ", Fuel Type: " << car.second.fuelType
                 << ", Transmission: " << car.second.transmission << ", Seating Capacity: " << car.second.seatingCapacity
                 << ", Times Rented: " << car.second.timesRented << endl;
        }
        printLine();
    }

    // Admin: Add a new car to the showroom
    void addCar(string name, double price, int quantity, string fuel, string transmission, int seating)
    {
        cars[name] = Car(name, price, quantity, fuel, transmission, seating);
        cout << "Car added successfully!\n";
    }

    // Admin: Edit an existing car's details
    void editCar(string name, double price, int quantity, string fuel, string transmission, int seating)
    {
        if (cars.find(name) != cars.end())
        {
            cars[name].price_per_day = price;
            cars[name].quantity = quantity;
            cars[name].fuelType = fuel;
            cars[name].transmission = transmission;
            cars[name].seatingCapacity = seating;
            cout << "Car details updated!\n";
        }
        else
        {
            throw runtime_error("Car not found in showroom!");
        }
    }

    // Admin: Remove a car from the showroom
    void removeCar(string name)
    {
        if (cars.find(name) != cars.end())
        {
            cars.erase(name);
            cout << "Car removed from showroom!\n";
        }
        else
        {
            throw runtime_error("Car not found in showroom!");
        }
    }

    // User: Rent a car and reduce the quantity, increase rental count
    Car rentCar(string name)
    {
        if (cars.find(name) != cars.end() && cars[name].quantity > 0)
        {
            cars[name].quantity--;
            cars[name].timesRented++;
            return cars[name];
        }
        else
        {
            throw runtime_error("Car not available or out of stock!");
        }
    }

    // User: Return a rented car
    void returnCar(string name)
    {
        if (cars.find(name) != cars.end())
        {
            cars[name].quantity++;
        }
        else
        {
            throw runtime_error("Car does not exist in showroom!");
        }
    }

    // Display cars rented most frequently
    void displayMostRentedCars()
    {
        printLine();
        cout << "Most Rented Cars:\n";
        for (auto &car : cars)
        {
            if (car.second.timesRented > 0)
            {
                cout << "Car: " << car.second.name << ", Times Rented: " << car.second.timesRented << endl;
            }
        }
        printLine();
    }
};

// User class with rental history
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