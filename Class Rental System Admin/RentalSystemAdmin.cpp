#include <iostream>
#include <vector>
using namespace std;

class Showroom
{
private:
    string showroom_Name;
    string showroom_Location;
    string phone_Number;

public:
    Showroom() : showroom_Name(""), showroom_Location(""), phone_Number("") {}

    void Showroom()
    {
        cout << "please enter your Showroom Name: ";
        cin >> showroom_Name;
        cout << "Please enter the Location of the Showroom: ";
        cin >> showroom_Location;
        cout << "Please enter the phone number: ";
        cin >> phone_Number;
    }
};

class Storage : public Showroom
{
private:
    vector<Showroom> show;

public:
    void Showroom()
    {
        cout << "please enter your Showroom Name: ";
        cin >> showroom_Name;
        cout << "Please enter the Location of the Showroom: ";
        cin >> showroom_Location;
        cout << "Please enter the phone number: ";
        cin >> phone_Number;

        show.push_back()
    }
};