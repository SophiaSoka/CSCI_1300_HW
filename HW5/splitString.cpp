// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 4 - Split String

#include <iostream>
#include <cassert>
using namespace std;

//parameters: input_string (string), separator (char), arr (string array), arr_size (int)
//returns: -1, 0 or he number of strings in array 
int split(string input_string, char separator, string arr[], int arr_size){
    //returns 0 if the string is empty 
    if(input_string.length() <= 0){
        return 0;
    }
    int count = 0;
    string word = "";
    //loops through string one char at a time 
    for(int i = 0; i < input_string.length(); i++){
        //if the array is full it returns -1 with as many possible index's filled 
        if (arr_size <= count){
            return -1;
        }
        //if char is the separator the previous characters(word) is added to array and reset 
        if(input_string[i] == separator){
            arr[count] = word;
            word = "";
            count++;
        }
        //if char is not seperator its added to the temp string word 
        else{
            word += input_string[i];
        }
    }
    //once gone through whole string, adds the lest "word" and returns the total number of strings added 
    arr[count] = word;
    count++;
    return count;
}

int main(){
    //test 1, test letters seperated by spaces 
    string test1_arr[5] = {};
    assert(split("ABC DEF GHI", ' ', test1_arr, 5) == 3);
    assert(test1_arr[0] == "ABC");
    assert(test1_arr[1] == "DEF");
    assert(test1_arr[2] == "GHI");
    //test 2, test string that doesn't split up 
    string test2_arr[5] = {};
    assert(split("ABCDEFGHI", ' ', test2_arr, 5) == 1);
    assert(test2_arr[0] == "ABCDEFGHI");
    //test 3, test the function will return -1 and still update string as much as possible
    string test3_arr[5] = {};
    assert(split("Bangkok,Berlin,Birmingham,Bogota,Busan,Baton Rouge,Beaumont,Boise,Budapest", ',', test3_arr, 5) == -1);
    assert(test3_arr[0] == "Bangkok");
    assert(test3_arr[1] == "Berlin");
    assert(test3_arr[2] == "Birmingham");
    assert(test3_arr[3] == "Bogota");
    assert(test3_arr[4] == "Busan");

}