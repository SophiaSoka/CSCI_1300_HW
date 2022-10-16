#include <iostream>
#include <string>
// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// HW 6 - Problem 2 - Mountain Stats 
#include <fstream>
#include <cassert>

using namespace std;

/*
    Takes a given file name and reads the contents, line by line 
    Finds detrementor in line and splits it 
    puts first half of line in array of strings for the names 
    puts second half of line in array of ints for the heights 
    now you have 2 arrays with heights and names with each mountain having an index 
    loops through the heights array to find largest and smallest value
    finds the names of mountains based on index of tallest and shortest 
    Parameters: filename(string)
    Returns: void, prints out three lines with number of mountains, the tallest and shortest mountain 
*/
void printMountainStats(string filename){
    //helping varaibles 
    int lines_read = 0;
    string names[100] = {"", "", "", "", "", "", "", "", "", ""};
    int heights[100] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string line; 
    ifstream fin;
    //opens file
    fin.open(filename); // Open input file
    //if file doesnt open, ends program 
    if (fin.fail())
    {
        cout << "Could not open file." << endl;
        return;
    }
    else
    {
        // read every line of file, count number of characters on each line
        
        while (getline(fin, line)) // continue looping as long as there is data to be processed in the file
        {
            //getline(fin, line);
            bool first_half = true;
            string name = "";
            int height = 0; 
            string height_str = "";
            if(line.length() > 0){
            for(int i = 0; i < line.length(); i++){
                //looking at name part of line
                if(first_half){
                    if(line[i] == '|'){ //end of name
                        names[lines_read] = name;
                        name = "";
                        first_half = false;
                    }
                    else{ //collecting name in string 
                        name += line[i];
                    }
                }
                //looking at height part of line 
                else{
                    //end of line
                    if(i >= line.length() - 1){//end of line
                        height_str += line[i];
                        height = stoi(height_str);//converts string into int 
                        heights[lines_read] = height;
                        height = 0;
                        height_str = "";
                        break;
                    }
                    else{
                        height_str += line[i];//collecting each digit in height 
                    }
                }
            }
            lines_read++;
            }            
        }
    //all lines have been read and all info is in correct array 
    string tall_name = names[0];
    int tall_height = heights[0];
    string short_name = names[0];
    int short_height = heights[0];
    //loops through height array to find the tallest and shortest mountain, keeps track of the names of mountains 
    for(int i = 1; i < lines_read; i++){
        if (heights[i] > tall_height){
            tall_height = heights[i];
            tall_name = names[i];
        }
        else if(heights[i] < short_height){
            short_height = heights[i];
            short_name = names[i];
        }
    }
    //prints out the correct information 
    cout << "Number of lines read: " << lines_read << "." << endl;
    cout << "Tallest mountain: " << tall_name << " at " << tall_height << " feet." << endl;
    cout << "Shortest mountain: " << short_name << " at " << short_height << " feet." << endl;

    }
}
//prints out info on 6 different files 
int main(){
    //test 1, example in github
    string file1 = "mountatin_data1.txt";
    printMountainStats(file1);
    cout << endl;
    //test 2, when file doesnt exists(edge case)
    string filename = "does-not-exist.txt";
    printMountainStats(filename);
    cout << endl;
    //test 3, example in github with space between data 
    string file2 = "mountain_data2.txt";
    printMountainStats(file2);
    cout << endl;
    //test 4, example with 5 mountains 
    string file3 = "mountatin_data3.txt";
    printMountainStats(file3);
    cout << endl;
    //test 5, example with all heights the same  
    string file4 = "mountain_data4.txt";
    printMountainStats(file4);
    cout << endl;
    //test 6, example where files dont match format 
    string file5 = "posts.txt";
    printMountainStats(file5);

    return 0;
}