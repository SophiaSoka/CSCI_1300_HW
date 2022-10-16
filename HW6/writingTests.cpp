// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// HW 6 - Problem 1 - Writing tests  
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

/*
    Counts the number of given characters
    found in the given input string. 
*/
int countCharacters(string input, char c)
{
    int count = 0;
    int input_len = input.length(); // store length of string in variable
    // loop through the string to check every character
    for (int i = 0; i < input_len; i++)
    {
        if (input[i] == c) // add one to total count if it matches desired character
            count += 1;
    }

    return count;
}

/*
    Takes a given file name and reads the contents. 
    Counts the occurences of letter on each line.
    Prints the line number and the number of occurences for each line.
    At the end, prints the total number of occurences.
    Returns true if the total number of occurences was greater than 20.

*/
bool readFile(string file_name, char letter)
{
    bool result = false;  // final result to return at end
    int total_count = 0;  // counts total occurrences of letter
    int line_count = 0;   // count of occurrences of letter for a single line

    string line;    // variable for storing each line as we read it
    ifstream fin;   // file input stream

    fin.open(file_name); // Open input file
    
    if (fin.fail())
    {
        cout << "File couldn't be opened!" << endl;
        result = false;
    }
    else
    {
        // read every line of file, count number of characters on each line
        int line_number = 0;
        while (!fin.eof()) // continue looping as long as there is data to be processed in the file
        {
            line_number += 1;
            getline(fin, line);

            line_count = countCharacters(line, letter);
            total_count += line_count;

            cout << "Line: " << line_number << ", Occurences: " << line_count << endl;
        } 
    
        // print the total count to user
        cout << "Total occurences: " << total_count << endl;

        // update result of function -- is true if total count greater than 20
        result = total_count > 20;

        // close files
        fin.close();
    }

    return result;
}

int main()
{
    ifstream fin;
    fin.open("shakespeare_sonnet.txt");
    // TESTING countCharacters()
    //counting number of a's in first line of sonnet
    string line1 = "From fairest creatures we desire increase,";
    assert(countCharacters(line1, 'a') == 3 );
    //counting number of a's in second line of sonnet 
    string line2 = "That thereby beautys rose might never die,";
    assert(countCharacters(line2, 'a') == 2 );
    //counting number of a's in forth line of sonnet 
    string line4 = "His tender heir might bear his memory.";
    assert(countCharacters(line4, 'a') == 1 );
    //counting number of space's in the string
    assert(countCharacters("hello how are you?", ' ') == 3 );
    //counting number of z's in first line of sonnet (edge case)
    assert(countCharacters(line1, 'z') == 0 );
    //counting number of a's in string with just a's (edge case)
    assert(countCharacters("aaaaaaaaaa", 'a') == 10 );


    // TESTING readFile()
    //expected output: 14 lines with at least 1 occurence on each line except lines 8, 11, and 13
    //expected output: "Total occurences: 28"
    assert(readFile("shakespeare_sonnet.txt", 'a') == true);
    cout << endl;
    //expected output: 14 lines with at least 1 occurence on each line
    //expected output: "Total occurences: 68"
    assert(readFile("shakespeare_sonnet.txt", 'e') == true);
    cout << endl;
    //expected output: 14 lines with 0 occurences on each line
    //expected output: "Total occurences: 0"
    assert(readFile("shakespeare_sonnet.txt", 'z') == false);
    cout << endl;
    //expected output: 14 lines with 0 occurences on each line
    //expected output: "Total occurences: 0"
    assert(readFile("shakespeare_sonnet.txt", '5') == false);
    cout << endl;
    //expected output: 14 lines with at least one occurences on each line
    //expected output: "Total occurences: 30"
    assert(readFile("shakespeare_sonnet.txt", 's') == true);
    cout << endl;
    //expected output: 26 lines with 0 occurences on each line except 1 on fisrt line
    //expected output: "Total occurences: 1"
    assert(readFile("alphabet.txt", 'a') == false);
    cout << endl;
    return 0;
}
