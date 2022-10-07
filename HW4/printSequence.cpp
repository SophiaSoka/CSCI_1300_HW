#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // declare all variables
    int start_num;
    int c_num = 0;
    bool start = true;
    
    // start
    while (start || (start_num <= 1 || start_num >= 1000) ) 
    { 
        // prompt the user and get their input
        cout << "Enter a value between 1 and 1000:" << endl;
        cin >> start_num;
        // input validation 
        if (start_num <= 1 || start_num >= 1000){
            cout << "Invalid input." << endl;
        }
        else{
            start = false;
            c_num = start_num;
        }
    }
    // if current number is greater than one sequency occurs, and prints each step 
    while(c_num > 1){
        cout << c_num << endl;
        if (c_num % 2 == 0)
        {
            c_num = floor(c_num/2);
        }
        else
        {
            c_num = (3 * c_num) + 1;
        }
    }
    // prints 1 as final step 
    cout << c_num << endl;

    return 0;
}