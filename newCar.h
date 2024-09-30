#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <sstream>
using namespace std;

class User
{
private:
    string LoginID, password;
    int what = 0; // to select whether a User or Admin

public:
    // constructor
    User() : LoginID(""), password(""), what(0) {} // since the data is not hardcoded so default constructor eles paramaterized constructor

    void setID(string ID);

    void setPass(string pass);

    string getID();

    string getPass();

    void Select();
    void registration();
    void Login();
};

// void User::Select();

// void User::registration();

// void User::Login();