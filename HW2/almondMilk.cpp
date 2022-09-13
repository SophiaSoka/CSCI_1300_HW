// CSCI 1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 – Zach Atkins
// Homework 2 - Problem # 3


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double length;
    double height;
    double oz;
    //asks user for length and height of code and stores input value 
    cout << "What is the side length of the base of the carton in inches? " << endl;
    cin >> length;
    cout << "What is the height of the carton in inches?"<< endl;
    cin >> height;
    //calculates fluid ounces 
    oz = 0.55 * (length * length * height);
    //print statement with ounces with one decimal place 
    cout << "The carton has a volume of " << fixed << setprecision(1) << oz  << " ounces."<< endl;
    return 0;

}
