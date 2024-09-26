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

    void Select();
    void registration();
    void Login();
};

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

        ofstream outfile("F:/cpp/Projects of OOPS/OOPs project/UserData.txt", ios::app);

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

        ofstream outfile("F:/cpp/Projects of OOPS/OOPs project/AdminData.txt", ios::app);

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

    ifstream infile("F:/cpp/Projects of OOPS/OOPs project/UserData.txt");
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

// class UserOptions
// {
// private:
//     string
// };

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
}
