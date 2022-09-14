#include <iostream>
using namespace std;

int main(){
    double speed_1, speed_2, speed_3;
    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> speed_1 >> speed_2 >> speed_3;
    //checks input is valid 
    if (speed_1 < 0 || speed_2 < 0 || speed_3 < 0)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    //checks if speed is decreasing 
    if (speed_1 > speed_2 && speed_2 > speed_3)
    {
        cout << "The wifi is getting slower!" << endl;
    }
    //checks if speed is increasing 
    else if (speed_1 < speed_2 && speed_2 < speed_3)
    {
        cout << "The wifi is getting faster!" << endl;
    }
    //default 
    else 
    {
        cout << "The wifi speed is changing unpredictably." << endl;
    }

    return 0;
}