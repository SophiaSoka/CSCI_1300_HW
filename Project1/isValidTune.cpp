// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 2 - Is Valid Tune

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
Algorithm: checks that the inputed string is only made of valid notes
    1. Inputs string 
    2. Checks to make sure the length is a multiple of two (if not, returns false)
    3. Loops through input and checks that every group of 2 characters is a vaild note
    4. If there is a substring that is not a valid note, flag is set to false 
    5. If one or more of the substrings created in loop isn't a valid note the function returns false 
    Parameters: note (string)
    Returns: boolean represtenting if string is made of only notes (bool)
*/
bool isValidTune(string input){
    //checks to make sure length is greater than 0 and a mulitple of 2
    if(input.length() >= 0 && input.length() % 2 == 0){
        //flag variable
        bool is_Valid_Note = true;
        for (int i = 0; i < input.length(); i += 2){
            //checks that each substring of 2 is a note
            if (!(isValidNote(input.substr(i, 2)))){
                is_Valid_Note = false;
            }   
        }
        return is_Valid_Note;
    }
    //if the input is not divisable by 2 returns false
    else{
        return false;
    }
}

int main(){
    //test 1, checking valid tune (true)
    bool result1 = isValidTune("A2B4C7");
    assert(result1 == 1);
    //test 2, checking wrong letter in tune (false)
    bool result2 = isValidTune("M5D2E1");
    assert(result2 == 0);
    //test 3, checking wrong numbers in tune (false)
    bool result3 = isValidTune("A5D2E11");
    assert(result3 == 0);
    //test 4, checkings random string (false)
    bool result4 = isValidTune("Hello1300");
    assert(result4 == 0);

}
