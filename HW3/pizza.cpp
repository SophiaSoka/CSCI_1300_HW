#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    string size;
    int toppings;
    double price = 0;
    //asks for user input and checks the stored value is valid 
    cout << "What size pizza would you like to order?" << endl;
    cin >> size;
    if (!(size == "S" || size == "M" || size == "L"))
    {
        cout << "Please enter a valid input."<< endl;
        return 0;
    }

    cout << "How many toppings do you want?" << endl;
    cin >> toppings;
    if (toppings < 0){
        cout << "Please enter a valid input."<< endl;
        return 0;
    }
    //inpouts are valid and the price is calculated based on the size 
    if (size == "S")
    {
        price = 4.99 + (toppings * 0.75);
    }
    else if (size == "M")
    {
        price = 5.99 + (toppings * 1.50);
    }
    else if (size == "L")
    {
        price = 6.99 + (toppings * 2.25);
    }

    cout << "Your total is $" << fixed << setprecision(2) << price << endl;
    return 0;
}