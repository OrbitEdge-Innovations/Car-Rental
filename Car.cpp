#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
#include <windows.h>
#include <vector>
using namespace std;

// Utility functions for better formatting
void printLine()
{
    cout << "--------------------------------------------------\n";
}

// Struct to store rental history
struct RentalHistory
{
    string carName;
    int days;
    double totalCost;
};

// Car class extended with more details
class Car
{
public:
    string name;
    double price_per_day;
    int quantity;
    string fuelType;
    string transmission;
    int seatingCapacity;
    int timesRented;

    Car(string n = "", double p = 0.0, int q = 0, string fuel = "", string trans = "", int seating = 0)
        : name(n), price_per_day(p), quantity(q), fuelType(fuel), transmission(trans), seatingCapacity(seating), timesRented(0) {}
};