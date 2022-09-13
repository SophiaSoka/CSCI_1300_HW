// CSCI 1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 – Zach Atkins
// Homework 2 - Problem # 4

#include <iostream>
using namespace std;

int main (){
    int days;
    //asks user for number of days 
    cout << "How many days in the future would you like a prediction for?" << endl;
    cin >> days;
    int b = 25;
    int v = 28;
    int cm = 40;
    //calculates inches for each mountain based on the diffence of snowfall and snow melted per day 
    b = b + (5 * days);
    v = v + (12 * days);
    cm = cm + (2 * days);
    //print statement for all mountains 
    cout << "Breckenridge will have " << b << " inches, Vail will have " << v << " inches, and Copper Mountain will have " << cm << " inches." << endl;
    return 0;
}