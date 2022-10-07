// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 3 - Number of Valid Notes 

#include <iostream>
using namespace std;

bool isValidNote(string note){
    //checks if the length is correct 
    bool output;
    if (note.length() == 2){
        //checks the first part is a correct letter and the second part if a correct number based on ASCII number 
        if((note[0] >= 65  && note[0] <= 71) && (note[1] >= 48 && note[1] <= 57) ){
            return true;
        }
    }
    //if length != 2, or either index doesn't pass test cases
    return false;
}
/*
Algorithm: counts the number of Valid Notes in a tune
    1. Inputs string, should be a valid tune  
    2. Creates count variable 
    3. Checks all potential substrings with the length of 2 in the tune
    4. If the substring is a valid tune incremnets the count variable 
    5. Returns the count 
    Parameters: tune (string)
    Returns: number of valid notes in tune (int)
*/
int numValidNotes(string tune){
    //creates count variable 
    int count = 0;
    for (int i = 0; i < tune.length(); i++){
        //checks all substrings for if they're a Valid note, if so adds to count 
        if (isValidNote(tune.substr(i, 2))){
            count++;
        }   
    }
    return count;
}


int main(){
    //test 1, checking invalid tune (0)
    int result1 = numValidNotes("I love comp sci!");
    assert(result1 == 0);
    //test 2, checking string with all valid notes (3)
    int result2 = numValidNotes("F4E2B0");
    assert(result2 == 3);
    //test 3, checking invalid tune with valid notes in it (2)
    int result3 = numValidNotes("ADB3M7G4F");
    assert(result3 == 2);
    //test 4, checkings edge cases (2)
    int result4 = numValidNotes("HC6MB1");
    assert(result4 == 2);
}
