// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 2 - Array Stats

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

//parameter arrary of doubles, length of array 
//returns lowest value in inputed array 
double min(double arr[], int arr_size){
    double lowest = arr[0];
    //loops through each double
    for(int i = 0; i < arr_size; i++){
        //if double is lowest found so far it updates tracker 
        if (arr[i] < lowest){
            lowest = arr[i];
        }
    }
    //returns lowest value 
    return lowest;
}

//parameter arrary of doubles, length of array 
//returns sum of doubles in inputed array 
double sum(double arr[], int arr_size){
    double sum = 0;
    //loops through every double in array and adds it to the total sum
    for(int i = 0; i < arr_size; i++){
        sum += arr[i];  
    }
    //returns the sum of doubles 
    return sum;
}

//parameter arrary of doubles, length of array 
//returns average value of inputed array 
double average(double arr[], int arr_size){
    double sum = 0;
    //finds the sum of the array 
    for(int i = 0; i < arr_size; i++){
        sum += arr[i];  
    }
    //returns the sum divided by the size of array  
    return (sum/arr_size);
}

//needed to test functions that return a double 
bool doublesEqual(double a, double b, const double epsilon = 1e-3)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

int main(){
    //first test for all three functions with simple array 
    double arr1[] = {1.24, 5.68, 3.456};
    int arr_size1 = 3;
    assert(doublesEqual(min(arr1, arr_size1), 1.240));
    assert(doublesEqual(sum(arr1, arr_size1), 10.376));
    assert(doublesEqual(average(arr1, arr_size1), 3.459));
    //second test for all three functions with array of just one number 
    double arr2[] = {0};
    int arr2_size = 1;
    assert(doublesEqual(min(arr2, arr2_size), 0.000));
    assert(doublesEqual(sum(arr2, arr2_size) ,0.000));
    assert(doublesEqual(average(arr2, arr2_size), 0.000));
    //third test for all three functions with array of ten numbers 
    double arr3[] = {0,1,2,3,4,5,6,7,8,9};
    int arr3_size = 10;
    assert(doublesEqual(min(arr3, arr3_size), 0.000));
    assert(doublesEqual(sum(arr3, arr3_size) ,45.000));
    assert(doublesEqual(average(arr3, arr3_size), 4.500));

    return 0;
}