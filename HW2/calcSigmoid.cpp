// CSCI 1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 – Zach Atkins
// Homework 2 - Problem # 6

#include <iostream>
#include <cmath>
using namespace std;

int main (){
    int x;
    double output;
    //ask user for input, saves input and calculates the sigmoid value 
    cout << "Enter a value for x:" << endl;
    cin >> x;
    output = 1 / (1 + exp(-1 * x));
    //print statement 
    cout << "The sigmoid for x=" << x << " is " << output << endl;
    return 0;
}