// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// HW 6 - Problem 3 - Reading Twitter Posts 
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

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

/*
    Takes a given file name and reads the contents, line by line 
    Finds detrementor in line and splits the post into an arr
    if there is 3 pieces of info in the line(representing a correct post) it adds to a count 
    returns count or -1 if file doesn't open 
    Parameters: filename(string)
    Returns: int, the number of posts in a file 
*/
int readPosts(string filename){
    //helping varibles 
    string arr[100];
    string line;
    ifstream fin;
    int temp_score;
    int count = 0;
    //opens file, if is unable returns -1
    fin.open(filename);
    if(fin.fail()){
        return -1;
    }
    else{
        while (!fin.eof()){ //loops through every line until theres nothing left 
            getline(fin, line);
            temp_score = split(line, ',', arr, 100);
            //if line is a post it adds one to count 
            if (temp_score == 3){
                count++;
            }
        }
        //returns count 
        return count++;
    }

    return 0;
}

int main(){
    //test 1, read example from github 
    string filename = "posts.txt";
    assert(readPosts(filename) == 3);
    //test 2, open file that doesn't exist 
    assert(readPosts("does-not-exist.txt") == -1);
    //test3, open file with no text in it 
    assert(readPosts("empty-file.txt") == 0);
    //test 4, open files with text but no posts 
    assert(readPosts("mountain_data2.txt") == 0);
    //test 5, file with some posts and some random text 
    assert(readPosts("posts2.txt") == 5);

}