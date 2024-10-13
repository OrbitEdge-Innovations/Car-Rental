#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include "RentalSystemAdmin.cpp"
using namespace std;

class User
{
private:
    string LoginID, password;
    int what = 0; // to select whether a User or Admin

public:
    // constructor
    User() : LoginID(""), password(""), what(0) {} // since the data is not hardcoded so default constructor eles paramaterized constructor

    void setID(string ID)
    {
        LoginID = ID;
    }

    void setPass(string pass)
    {
        password = pass;
    }

    string getID()
    {
        return LoginID;
    }

    string getPass()
    {
        return password;
    }

    void User::Select()
    {
        cout << "Are you a?" << endl;
        cout << "User" << endl;
        cout << "Admin" << endl;

        cout << "Press 1 for the User" << endl;
        cout << "Press 2 for the Admin" << endl;
        cin >> what;
    }

    void User::registration()
    {
        system("cls");
        string id, pass;

        if (what == 1)
        { // Registering as a User in a User data file
        start:
            cout << "Please enter your id: ";
            cin >> id;
            setID(id);

            cout << "Please enter the password: ";
            cin >> pass;

            if (pass.length() < 8)
            {
                cout << "please enter at least 8 character in your password." << endl;
                goto start;
            }

            else
            {
                setPass(pass);
            }

            ofstream outfile("C:/Users/ASUS/Downloads/faltu/Car Rental Haardik/Car-Rental/UserData.txt", ios::app);

            if (!outfile)
            {
                cout << "Error: the file cannot be opened." << endl;
            }

            else
            {
                outfile << "User" << "\t" << getID() << "\t" << getPass() << endl;
                cout << "\t User Registered Successfully" << endl;
            }

            outfile.close();
            cout << "Returning to the main window";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(800);
            }
            Sleep(3000);
        }

        if (what == 2)
        { // Registering as a User in a User data file
        start1:
            cout << "Please enter your id: ";
            cin >> id;
            setID(id);

            cout << "Please enter the password: ";
            cin >> pass;

            if (pass.length() < 8)
            {
                cout << "please enter at least 8 character in your password." << endl;
                goto start;
            }

            else
            {
                setPass(pass);
            }

            ofstream outfile("C:/Users/ASUS/Downloads/faltu/Car Rental Haardik/Car-Rental/AdminData.txt", ios::app);

            if (!outfile)
            {
                cout << "Error: the file cannot be opened." << endl;
            }

            else
            {
                outfile << "User" << "\t" << getID() << "\t" << getPass() << endl;
                cout << "\t User Registered Successfully" << endl;
            }

            outfile.close();
            cout << "Returning to the main window";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(800);
            }
            Sleep(3000);
        }
    }

    void User::Login()
    {

        system("cls");
        string id, pass;

        cout << "Please enter your ID: ";
        cin >> id;

        cout << "Please enter your Password: ";
        cin >> pass;

        if (what == 1)
        {
            ifstream infile("C:/Users/ASUS/Downloads/faltu/Car Rental Haardik/Car-Rental/UserData.txt");
            if (!infile)
            {
                cout << "Error:cannot open the file!" << endl;
            }

            else
            {
                string line;
                bool found;

                while (getline(infile, line))
                {
                    stringstream ss;

                    ss << line;
                    string isUorA, UserID, UserPass;
                    char delimiter;
                    ss >> isUorA >> UserID >> UserPass;

                    if (id == UserID && pass == UserPass)
                    {
                        found = true;
                        cout << "Please wait";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << ".";
                            Sleep(800);
                        }
                        system("cls");
                        cout << "Welcome to this Page" << endl;
                    }
                }

                if (!found)
                {
                    cout << "Error: Incorrect details have been entered" << endl;
                }
            }
        }

        if (what == 2)
        {

            ifstream infile("C:/Users/ASUS/Downloads/faltu/Car Rental Haardik/Car-Rental/AdminData.txt");
            if (!infile)
            {
                cout << "Error:cannot open the file!" << endl;
            }

            else
            {
                string line;
                bool found;

                while (getline(infile, line))
                {
                    stringstream ss;

                    ss << line;
                    string isUorA, UserID, UserPass;
                    char delimiter;
                    ss >> isUorA >> UserID >> UserPass;

                    if (id == UserID && pass == UserPass)
                    {
                        found = true;
                        cout << "Please wait";
                        for (int i = 0; i < 3; i++)
                        {
                            cout << ".";
                            Sleep(800);
                        }
                        system("cls");
                        cout << "Welcome to this Page" << endl;
                        Storage S;
                        S.showMenu();
                    }
                }

                if (!found)
                {
                    cout << "Error: Incorrect details have been entered" << endl;
                }
            }
        }
    }
};
