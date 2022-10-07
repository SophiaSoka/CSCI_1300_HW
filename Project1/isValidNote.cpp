// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 1 - Is Valid Note

#include <iostream>
#include <cassert>
using namespace std;

/*
Algorithm: checks that the inputed string is a vaild musical note and tune
    1. Inputs string
    2. Checks to make sure the length is two (if not, returns false)
    3. Takes index 0 and makes sure it's a capital letter from A to G (inclusive) 
    4. Takes index 1 and mkes sure it's a single digit number 
    5. If both indexs are correct print true; if one or both is false, prints false 
    Parameters: note (string)
    Returns: boolean represtenting if string is a note (bool)
*/
//ASCII value of A == 65, G == 71, 0 == 48, 9 == 57
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


int main(){
    //test 1, checking one letter (false)
    bool result1 = isValidNote("X");
    assert(result1 == 0);
    //test 2, correct Tune (true)
    bool result2 = isValidNote("D4");
    assert(result2 == 1);
    //test 3, lowercase letter (false)
    bool result3 = isValidNote("d4");
    assert(result3 == 0);
    //test 4, two digit number (false)
    bool result4 = isValidNote("E72");
    assert(result4 == 0);
    //test 5, only letters (flase)
    bool result5 = isValidNote("qu");
    assert(result5 == 0);
    //test 6, only numbers (false)
    bool result6 = isValidNote("56");
    assert(result6 == 0);
    //test 7, first edge case (true)
    bool result7 = isValidNote("A0");
    assert(result7 == 1);
    //test 8, last edge case (true)
    bool result8 = isValidNote("G9");
    assert(result8 == 1);
    return 0;

}
