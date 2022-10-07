// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 3b - Second Place

#include <iostream>
#include <cassert>
using namespace std;


bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert){
    if (num_elements >= arr_size){
        return false;
    }
    else if (index > num_elements){
        return false;
    }
    for ( int i = num_elements; i > index+1; i--){
        input_strings[i] = input_strings[i-1];
    }
    input_strings[index+1] = string_to_insert;
    return true;

}

//parameters: input_strings[] (string array), string_to_insert(string), string_to_find (string), num_elements(int), size(int), count(int) 
//returns: new num_elements (int) if all strings are succefully added the new number of elements, if it wasn't successful returns original number of elements 
int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int size, int count){
    //creates copy of arr to not be modified  
    string og[size];
    for(int i = 0; i < size; i++){
        og[i] = input_strings[i];
    }
    //tracker variables 
    int index;
    int strings_added = 0;
    //will not be modifiled, prints of oriinal number if it fails 
    const int fail = num_elements;
    //loops through each string in array 
    for (int i = 0; i < size; i++){
        //if string is the one we are looking for it holds onto that index 
        if(input_strings[i] == (string_to_find)){
            index = i;
            //if insert of word is successful it increments tracking variables 
            if (insertAfter(input_strings, num_elements, size, index, string_to_insert)){
                strings_added++;
                num_elements++;
            }
            //if insert of word is unsuccessful it puts array back to orginal and returns orginal num_elements 
            else{
                for(int i = 0; i < size; i++){
                    input_strings[i] = og[i];
                }
                return fail;
            }
        }
    }
    //if the program added the correct amount of strings it returns new number of strings in array 
    if(strings_added == count){
        return num_elements;
    }
    //if nothing has been returned then it sets array back to original and returns orginal num_elements 
    for(int i = 0; i < size; i++){
        input_strings[i] = og[i];
    }
    return fail;
}

int main(){

    //test 1 testing adding one nunber 
    string test1_arr[9] = {"1", "2", "3", "5", "6", "7"};
    secondPlace(test1_arr, "0", "3", 6, 9, 1);
    assert(test1_arr[0] == "1");
    assert(test1_arr[1] == "2");
    assert(test1_arr[2] == "3");
    assert(test1_arr[3] == "0");
    assert(test1_arr[4] == "5");
    assert(test1_arr[5] == "6");
    assert(test1_arr[6] == "7");


    //test 2 testing adding multiple words 
    string test2_arr[10] = {"pikachu", "clefairy", "pikachu", "pikachu", "eevee"};
    secondPlace(test2_arr, "added", "pikachu", 5, 10, 3);
    assert(test2_arr[0] == "pikachu");
    assert(test2_arr[1] == "added");
    assert(test2_arr[2] == "clefairy");
    assert(test2_arr[3] == "pikachu");
    assert(test2_arr[4] == "added");
    assert(test2_arr[5] == "pikachu");
    assert(test2_arr[6] == "added");
    assert(test2_arr[7] == "eevee");

    
    //test 3 testing that function will fail 
    string test3_arr[3] = {"this", "shouldn't", "work"};
    secondPlace(test3_arr, "added", "this", 1, 3, 3);
    assert(test3_arr[0] == "this");
    assert(test3_arr[1] == "shouldn't");
    assert(test3_arr[2] == "work");
    

    return 0;
}
