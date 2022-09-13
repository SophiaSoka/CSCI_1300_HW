// CSCI 1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 – Zach Atkins
// Homework 2 - Problem # 5

#include <iostream>
using namespace std;

int main (){
    int bolts;
    int gems; 
    int gold_coins;
    //ask user for input of total bolts 
    cout << "Enter the number of Bolts:" << endl;
    cin >> bolts;
    //calculates number of gems 
    gems = bolts / 299;
    bolts = bolts % 299;
    //calculates number of gold coins 
    gold_coins = bolts / 23;
    //set remianing bolts 
    bolts = bolts % 23;
    //print statement for all values 
    cout << gems << " Gem(s) " << gold_coins << " GoldCoin(s) " << bolts << " Bolt(s)" << endl;

    return 0;
}