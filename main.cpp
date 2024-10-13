#include <iostream>
#include "newCar.cpp"
#include "AdminMenu.cpp"
#include "UserMenu.cpp"
#include "ShowRoom.cpp"
using namespace std;

int main()
{
    User Use;

    bool exit = false; // this is being used as a flag to allow user to exit out of our form by turning the value of
    // exit to true
    Use.Select();
    while (!exit)
    {                  // this loop will work until the user selects the exit btton and turns the value of the exit to true which !true => flase thus while loop will stop
        system("cls"); // this line will help you hide the previous output and only display the current output on the screen
        int val;       // we will give the user 3 option to REGISTER, LOGIN , EXIT

        cout << "\tWelcome To Registration & Login Form" << endl;
        cout << "\t************************************" << endl;
        cout << "\t1.Register." << endl;
        cout << "\t2.Login." << endl;
        cout << "\t3.Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1)
        {
            Use.registration();
        }

        else if (val == 2)
        {
            Use.Login();
        }

        else if (val == 3)
        {
            system("cls");
            exit = true;
            cout << "\tBye Bye!!" << endl;
            Sleep(3000);
        }
        Sleep(3000);
    }

    User user;
    Showroom showroom;

    // Simulating a login system
    string id, pass;
    cout << "Enter your ID: ";
    cin >> id;
    user.setID(id);

    if (id == "Admin")
    {
        adminMenu(showroom);
    }
    else
    {
        userMenu(user, showroom);
    }

    return 0;
}