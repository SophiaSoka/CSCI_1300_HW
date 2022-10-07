// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 1 - Array Pilgrimage

#include <iostream>
#include <cassert>
using namespace std;

int main(){
    //creates array of ints from 5 to 14
    int distances[10];
    for ( int i = 0; i < 10; i++){
        distances[i] = i+5;
        //prints out number on its own line after its added to array 
        cout << distances[i] << endl;
    }
    //creates array of strings with names of five cities 
    string cities[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};
    //loops through the array and prints out each string on new line
    for(int i = 0; i < 5; i++){
        cout << cities[i] << endl;
    }
    //creates array of ints with first 100 multiples of 6
    int sequence[100];
    for(int i = 0; i < 100; i ++){
        sequence[i] = (i+1) * 6;
        //prints out number on new line 
        cout << sequence[i] << endl;
    }
    //creats array of char and tracker variable 
    char letters[52];
    int count = 0;
    for(int i = 0; i < 52; i++){
        //if letter is capital 
        if (i % 2 == 0){
            letters[i] = 65 + count;
        }
        else{ //if letter is lowercase, then moves to next letter 
            letters[i] = 97 + count;
            count ++;
        }
        //prints out char on new line
        cout << letters[i] << endl;
    }
    return 0;
}

