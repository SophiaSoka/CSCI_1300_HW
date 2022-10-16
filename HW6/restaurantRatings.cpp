// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// HW 6 - Problem 4a - Restaurant Ratings  
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

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

/*
    Takes a given file name and reads the contents, line by line 
    Finds detrementor in line and splits contents into temp array
    puts first item of line into a array of strings 
    puts ratings of resturant into a row or 2D array of ints 
    adds to the count of resturants 
    returns the total count 
    Parameters: filename(string), restaurants (strings[]), ratings (int[][3]), arrSize (int) 
    Returns: int with the count of restaurants 
*/
int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arrSize){
    //helping variables 
    ifstream fin;
    string line;
    string rate_str;
    int count = 0;
    int rate1;
    int rate2;
    int rate3;
    int temp_size;
    string temp_arr[10];
    //returns -1 if file cant open 
    fin.open(filename);
    if(fin.fail()){
        return -1;
    }
    //loops through file until theres nothing else to read 
    while(!fin.eof()){
        //gets line and splits it into array of strings
        getline(fin, line);
        temp_size = split(line,'~', temp_arr, 101);
        //if line has valid input for a resturant, adds info into the correct array 
        if(temp_size == 4){
            //puts name in restaurants array 
            restaurants[count] = temp_arr[0];
            rate_str = temp_arr[1];
            rate1 = stoi(rate_str);
            ratings[count][0]= rate1;//stores rating one as int 
            rate_str = temp_arr[2];
            rate2 = stoi(rate_str);
            ratings[count][1]= rate2;//stores rating one as int 
            rate_str = temp_arr[3];
            rate3 = stoi(rate_str);
            ratings[count][2]= rate3;//stores rating one as int 
            //counts number of valid restaurants 
            count ++;
        }
        //stops running if arr runs out of space 
        if(count >= arrSize){
            return count;
        }
    }
    //returns count 
    return count;
}

int main(){
    //test 1, example from github 
    string filename = "restaurant_samples.txt";
    string restaurants[3];
    int ratings[3][3];
    assert(readRestaurantData(filename, restaurants, ratings, 3) == 3);
    //test 2, example of file that doesn't oen 
    assert(readRestaurantData("does-not-exist.txt", restaurants, ratings, 3) == -1);
    //test 3, exampele with 2 small of an array 
    string small_array[2];
    int small_2D[2][3];
    assert(readRestaurantData(filename, small_array, small_2D, 2) == 2);
    //assert 4, blank liness 
    assert(readRestaurantData("empty-file.txt", restaurants, ratings, 3) == 0);
}