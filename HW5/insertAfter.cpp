#include <iostream>
// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 3a - Insert After

#include <cassert>
#include <iomanip>
using namespace std;


//parameters: input_strings[] (string array), num_elements (int), arr_size (int), index(int), string_to_insert (string)
//returns: boolean, true if string is asserted correctly false otherwise
bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert){
    //returns false if theres no more space in array 
    if (num_elements >= arr_size){
        return false;
    }
    //returns false idf index isn't in bounds 
    else if (index > num_elements){
        return false;
    }
    //moves all strings after index over one to create space for new string at index 
    for ( int i = num_elements; i > index+1; i--){
        input_strings[i] = input_strings[i-1];
    }
    //places in string in empty index 
    input_strings[index+1] = string_to_insert;
    //returns true after task is complete;
    return true;

}

int main(){
    //test 1 testing adding nunber at the end
    string test1_arr[5] = {"1", "2", "3"};
    insertAfter(test1_arr, 3, 5, 2, "4");
    assert(test1_arr[0] == "1");
    assert(test1_arr[1] == "2");
    assert(test1_arr[2] == "3");
    assert(test1_arr[3] == "4");


    //test 2 testing adding word at the begging of array 
    string test2_arr[7] = {"pikachu", "clefairy", "snorlax", "caterpie", "pichu", "eevee"};
    insertAfter(test2_arr, 6, 7, 0, "meowth");
    assert(test2_arr[0] == "pikachu");
    assert(test2_arr[1] == "meowth");
    assert(test2_arr[2] == "clefairy");
    assert(test2_arr[3] == "snorlax");
    assert(test2_arr[4] == "caterpie");
    assert(test2_arr[5] == "pichu");
    assert(test2_arr[6] == "eevee");
    
    //test 3 testing that function will return false when theres no room in array
    string test3_arr[3] = {"this", "shouldn't", "work"};
    insertAfter(test3_arr, 3, 3, 0, "nah");
    assert(insertAfter(test3_arr, 3, 3, 0, "nah") == 0);

}

