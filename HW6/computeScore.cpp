// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// HW 6 - Problem 4b - Computing score 
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;
//helper function 
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
//helper function 
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
/*    
    loops through every restaurant in array  
    calculates the score of each resturant 
    prints out name and score, then loop countainues to next index 
    Parameters: restaurants (strings[]), ratings (int[][3]), num_restaurants(int) 
    Returns: void, prints out score for every restaurant in array 
*/
void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants){
    //helping variables 
    double score;
    string name;
    //loops through restaurants and ratings 
    for(int i = 0; i < num_restaurants; i++){
        name = restaurants[i];
        //calculates score 
        score = ((6.3*ratings[i][0]) + (4.3*ratings[i][1]) + (3.4*(5-ratings[i][2])));
        //prints out eac resturants info on its own line 
        cout << name << " overall score: " << fixed << setprecision(1) << score << endl;
    }
}

int main(){
    //test 1, given in github 
    string filename = "restaurant_samples.txt";
    int num_restaurants = 3;
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];
    int num_lines = readRestaurantData(filename, restaurants, ratings, num_restaurants);
    if (num_lines == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        calcOverallScore(restaurants, ratings, num_lines);
    }
    cout << endl;
    //test 2, another with more resturants 
    //expected: 
    string restaurants2[10];
    int ratings2[10][3];
    int num = readRestaurantData("restaurant_more_examples.txt", restaurants2, ratings2, 10);
    calcOverallScore(restaurants2, ratings2, num);
    cout << endl;
    //test 3, exampele with 2 small of an array
    //expected: first 2 resturants in file with their score 
    string small_array[2];
    int small_2D[2][3];
    int number = readRestaurantData(filename, small_array, small_2D, 2);
    calcOverallScore(small_array, small_2D, number);
    cout << endl;
    //assert 4, blank liness 
    //expected: nothing printed 
    string restaurants4[10];
    int ratings4[10][3];
    int output =readRestaurantData("empty-file.txt", restaurants4, ratings4, 3);
    calcOverallScore(restaurants4, ratings4, output);
    cout << endl;

    return 0;
}