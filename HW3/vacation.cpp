#include <iostream>
using namespace std;

int main() 
{
    // declare all the variables
    double budget;
    string transportation;

    // prompt the user & get their inputs
    cout << "What is your budget?" << endl;
    cin >> budget;
    if  ( budget <= 0)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> transportation;

    // input validation: budget must be positive
    if ( !(transportation == "B" || transportation == "T" || transportation == "A" ) )
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }

    // decide if it's in Bus budget
    if ( transportation == "B"){
        if( budget >= 175.25) 
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
    }

    // decide if it's in Train budget
    if ( transportation == "T"){
        if( budget >= 240.66) 
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
    }

    // decide if it's in Plane budget
    if ( transportation == "A"){
        if( budget >= 350.93) 
        {
            cout << "Yes, this vacation is within your budget!" << endl;
        }
        else
        {
            cout << "Sorry, this vacation is outside your budget." << endl;
        }
    }

    return 0;
}