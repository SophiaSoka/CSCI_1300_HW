// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 6 - Test Me

#include <iostream>
#include <cassert>
using namespace std;

int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    		arr[i] = 5; 
            count++;//added this line b/c count needs to increment after element is changed 
		}
	}
	return count;
}


int main(){
    // test 1, edge case
    int arr1[5] = {0, 1, 2, 3, 4};
    assert(zeroesToFives(arr1, 5) == 1);
    assert(arr1[0] == 5);
    assert(arr1[1] == 1);
    assert(arr1[2] == 2);
    assert(arr1[3] == 3);
    assert(arr1[4] == 4);
    // test 2, all 0's
    int arr2[3] = {0, 0, 0};
    assert(zeroesToFives(arr2, 3) == 3);
    assert(arr2[0] == 5);
    assert(arr2[1] == 5);
    assert(arr2[2] == 5);
    //test 3, no 0's or 5's
    int arr3[3] = {2, 3, 4};
    assert(zeroesToFives(arr3, 3) == 0);
    assert(arr3[0] == 2);
    assert(arr3[1] == 3);
    assert(arr3[2] == 4);
    //test 4, all 5's
    int arr4[3] = {5, 5, 5};
    assert(zeroesToFives(arr4, 3) == 0);
    assert(arr4[0] == 5);
    assert(arr4[1] == 5);
    assert(arr4[2] == 5);
    //test 5, edge case
    int arr5[3] = {2, 1, 0};
    assert(zeroesToFives(arr5, 3) == 1);
    assert(arr5[0] == 2);
    assert(arr5[1] == 1);
    assert(arr5[2] == 5);
    //test 6, negative numbers 
    int arr6[3] = {-2, -1, 0};
    assert(zeroesToFives(arr6, 3) == 1);
    assert(arr6[0] == -2);
    assert(arr6[1] == -1);
    assert(arr6[2] == 5);
    //test 7, long array 
    int arr7[10] = {-2, -1, 0, 1, 2, 0, 0, 3, 0, 0};
    assert(zeroesToFives(arr7, 10) == 5);
    assert(arr7[0] == -2);
    assert(arr7[1] == -1);
    assert(arr7[2] == 5);
    assert(arr7[3] == 1);
    assert(arr7[4] == 2);
    assert(arr7[5] == 5);
    assert(arr7[6] == 5);
    assert(arr7[7] == 3);
    assert(arr7[8] == 5);
    assert(arr7[9] == 5);
    //test 8 empty array 
    int arr8[] = {};
    assert(zeroesToFives(arr8, 0) == 0);
    //test 9 just a zero, edge case
    int arr9[1] = {0};
    assert(zeroesToFives(arr9, 1) == 1);
    assert(arr9[0] == 5);
    //test 10, 
    int arr10[5] = {11, 82, 0 , -1, -901};
    assert(zeroesToFives(arr10, 5) == 1);
    assert(arr10[0] == 11);
    assert(arr10[1] == 82);
    assert(arr10[2] == 5);
    assert(arr10[3] == -1);
    assert(arr10[4] == -901);

    
}