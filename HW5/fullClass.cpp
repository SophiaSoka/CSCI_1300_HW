// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 5 - Full Class

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;


//parameters: classroom[][4] (bool 2D array), rows (int), waitlist (int)
//returns: remaining waitlsit(int) and prints out the updted classroom array
int fullClass(bool classroom[][4], int rows, int waitlist){
    //loops through every row and coloume 
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < 4; c++){
            //if seat is open and a student needs it, it is filled and theyre taken off waitlist 
            if(classroom[r][c] == 0 && waitlist > 0){
                classroom[r][c] = 1;
                waitlist--;
            }
            //prints out seat status 
            cout << classroom[r][c];
        }
        cout << endl;
    }
    //prints out the return value 
    cout << "Remaining Students: " << waitlist << endl;
    return waitlist;
}

int main(){
    //test 1
    bool classroom1[3][4] = {{0, 0, 0, 0},{1, 1, 1, 1},{0, 0, 0, 0}};
    assert(fullClass(classroom1, 3, 9) == 1);
    cout << endl;
    //test 2
    bool classroom2[4][4] = {{0, 1, 1, 1},{0, 0, 0, 0},{1, 1, 0, 0}, {0, 1, 0, 1}};
    assert(fullClass(classroom2, 4, 6) == 0);
    cout << endl;
    //test 3
    bool classroom3[4][4] = {{0, 1, 0, 1},{0, 0, 0, 0},{1, 0, 0, 0}, {0, 1, 0, 1}};
    assert(fullClass(classroom3, 4, 16) == 5);
    cout << endl;

    return 0;
}