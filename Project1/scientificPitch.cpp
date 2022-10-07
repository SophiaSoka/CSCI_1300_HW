// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 7 - Secientific Pitch

#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

//Problem 1, Is Valid Note Function 
bool isValidNote(string note){
    //checks if the length is correct 
    bool output;
    if (note.length() == 2){
        //checks the first part is a correct letter and the second part if a correct number based on ASCII number 
        if((note[0] >= 65  && note[0] <= 71) && (note[1] >= 48 && note[1] <= 57) ){
            return true;
        }
    }
    //if length != 2, or either index doesn't pass test cases
    return false;
}

//Problem 2, Is Valid Tune Function 
bool isValidTune(string input){
    //checks to make sure length is greater than 0 and a mulitple of 2
    if(input.length() >= 0 && input.length() % 2 == 0){
        //flag variable
        bool is_Valid_Note = true;
        for (int i = 0; i < input.length(); i += 2){
            //checks that each substring of 2 is a note
            if (!(isValidNote(input.substr(i, 2)))){
                is_Valid_Note = false;
            }   
        }
        return is_Valid_Note;
    }
    //if the input is not divisable by 2 returns false
    else{
        return false;
    }
}

//Problem 4, returns tune similarity (command == 1)
double tuneSimilarity(string tune1, string tune2)
{
    // checks that both tunes are the same length
    if (tune1.length() != tune2.length())
    {
        return 0;
    }
    // varibles to keep track of for final equation
    int notes = tune1.length() / 2;
    double same_note = 0;
    int same_pitch = 0;
    int diff_note = 0;
    // substrings that represent notes from each tune that will be compared in for loop
    string note1;
    string note2;
    for (int i = 0; i < notes * 2; i += 2)
    {
        // loops through each note in each tune and compares them
        note1 = tune1.substr(i, 2);
        note2 = tune2.substr(i, 2);
        // if notes are identical both counting variables are incremented
        if (note1 == note2)
        {
            same_note++;
            same_pitch++;
        }
        // if just the note is equal, but not the pitch the same_note variable is incremented
        else if (note1[0] == note2[0])
        {
            same_note++;
        }
        // if the two notes have nothing in common the diif_note variable is incremented
        else if (note1[0] != note2[0] && note1[1] != note2[1])
        {
            diff_note++;
        }

    }
    double output = (double)(same_note / notes) + same_pitch - diff_note;
    return output;
}

//Problem 5, returns best tune similarity of differnt length strings (command == 2)
double bestSimilarity(string inputTune, string targetTune)
{
    //checks that inputs are valid 
    if (targetTune.length() > inputTune.length())
    {
        return 0;
    }
    //creates all necessary tracking variables 
    int len = targetTune.length();
    double best_score = tuneSimilarity(inputTune.substr(0, len), targetTune);
    double current_score;
    string section;
    //loops through input tune and creates substring with all possible tunes the same length as target 
    for (int i = 0; i <= inputTune.length() - len; i += 2)
    {
        section = inputTune.substr(i, len);
        current_score = tuneSimilarity(section, targetTune);
        //if current score is the best score found so far, best score is updated 
        if (current_score > best_score)
        {
            best_score = current_score;
        }
    }
    //best score is returned 
    return best_score;
}

//Problem 6, prints Tune ranks of the tunes compared to 4th input, target tune (command == 3)
void printTuneRankings(string tune1, string tune2, string tune3, string targetTune){
    //finds best score for all tunes compared to the target 
    double rank1 = bestSimilarity(tune1, targetTune);
    double rank2 = bestSimilarity(tune2, targetTune);
    double rank3 = bestSimilarity(tune3, targetTune);
    //rank tracking variables 
    string best; 
    string second; 
    string worst;
    //if tune one is the most similar to target 
    if(rank1 >= rank2 && rank1 >= rank3){
        best = "Tune 1";
        //finds second and third rankings 
        if (rank2 >= rank3){
            second = "Tune 2";
            worst = "Tune 3";
        }
        else{
            second = "Tune 3";
            worst = "Tune 2";
        }

    }
    //if tune two is the most similar to target 
    else if (rank2 >= rank1 && rank2 >= rank3){
        best = "Tune 2";
        //finds second and third rankings 
        if (rank1 >= rank3){
            second = "Tune 1";
            worst = "Tune 3";
        }
        else{
            second = "Tune 3";
            worst = "Tune 1";
        }

    }
    //if tune three is the most similar to target 
    else{
        best = "Tune 3";
        //finds second and third rankings 
        if (rank1 >= rank2){
            second = "Tune 1";
            worst = "Tune 2";
        }
        else{
            second = "Tune 2";
            worst = "Tune 1";
        }
    }
    //prints rankings list to terminal
    cout << "1) " << best << ", 2) "<< second << ", 3) " << worst << endl;

    return;
}


/*
Algorithm: provides menu for use of different functions  
    1. Prints menu, propting user for a number 1-4
    2. Stores the choice of the user and based on choice enters different part of switch statement 
    3. Based on the choice, computer prompts user for needed inputs until the inputs are valid SPN's
    4. Once inputs are all valid the chossen function is run and returns or prints out corresponding answer 
    5. Menu is then printed again and cycle repeats until user picks 4 on the menu 
    6. Once 4 is the choice Goodbye staement is printed and the main() stops 
*/
int main(){
    int command;
    //will always loop until case 4 where it returns a value and stops
    while(true){
        //menu is printed with options 
        cout << "--- Menu ---" << endl;
        cout << "1. Calculate similarity between two tunes." << endl;
        cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
        cout << "3. Print three input tunes in order from most to least similar to the target tune." << endl;
        cout << "4. Exit." << endl;
        cout << "Please enter your choice (1 - 4): " << endl;
        cin >> command;
        
        switch(command)
        {
        case 1: //Similarity between two tunes 
        {
            bool validSPN;
            string first_input = "";
            string second_input = ""; 
            //Inputs first tune, checks that it is a valid tune
            cout << "Please enter the first tune:" << endl;
            cin >> first_input;
            validSPN = isValidTune(first_input);
            while (!validSPN)
            {
                cout << "Invalid Input. Please enter a tune in valid SPN: " << endl;
                cin >> first_input;
                validSPN = isValidTune(first_input);
            }
            //Inputs second tune, checks that it is a valid tune 
            cout << "Please enter the second tune:" << endl;
            cin >> second_input;
            validSPN = isValidTune(second_input);
            while (!validSPN)
            {
                cout << "Invalid Input. Please enter a tune in valid SPN: " << endl;
                cin >> second_input;
                validSPN = isValidTune(second_input);
            }
            //tune similarity is printed to the hundreths place, then menu is reprinted 
            cout << "The similarity score is " << setprecision(2) << fixed << tuneSimilarity(first_input, second_input) << endl;
            break;
        }
        case 2: // best similarity of two tunes that may be different lengths 
        {
            bool validSPN;
            string tune_input = "";
            string target_input = ""; 
            //Inputs first tune, checks that it is a valid tune
            cout << "Please enter the input tune:" << endl;
            cin >> tune_input;
            validSPN = isValidTune(tune_input);
            while (!validSPN)
            {
                cout << "Invalid Input. Please enter a tune in valid SPN: " << endl;
                cin >> tune_input;
                validSPN = isValidTune(tune_input);
            }
            //Inputs target tune, checks that it is a valid tune
            cout << "Please enter the target tune:" << endl;
            cin >> target_input;
            validSPN = isValidTune(target_input);
            while (!validSPN)
            {
                cout << "Invalid input. Please enter a tune in valid SPN: " << endl;
                cin >> target_input;
                validSPN = isValidTune(target_input);
            }
            //best similarity is printed to the hundreths place, then menu is reprinted 
            cout << "The best similarity score is " << setprecision(2) << fixed << bestSimilarity(tune_input, target_input) << endl;
            break;
        }
        case 3: //tune rankings is printed 
        {
            bool validSPN;
            string first_input = "";
            string second_input = ""; 
            string third_input = "";
            string target_input = "";
            //Inputs first tune, checks that it is a valid tune
            cout << "Please enter the first tune:" << endl;
            cin >> first_input;
            validSPN = isValidTune(first_input);
            while (!validSPN)
            {
                cout << "Invalid input. Please enter a tune in valid SPN: " << endl;
                cin >> first_input;
                validSPN = isValidTune(first_input);
            }
            //Inputs second tune, checks that it is a valid tune
            cout << "Please enter the second tune:" << endl;
            cin >> second_input;
            validSPN = isValidTune(second_input);
            while (!validSPN)
            {
                cout << "Invalid input. Please enter a tune in valid SPN: " << endl;
                cin >> second_input;
                validSPN = isValidTune(second_input);
            }
            //Inputs third tune, checks that it is a valid tune
            cout << "Please enter the third tune:" << endl;
            cin >> third_input;
            validSPN = isValidTune(third_input);
            while (!validSPN)
            {
                cout << "Invalid input. Please enter a tune in valid SPN: " << endl;
                cin >> third_input;
                validSPN = isValidTune(third_input);
            }
            //Inputs target tune, checks that it is a valid tune
            cout << "Please enter the target tune:" << endl;
            cin >> target_input;
            validSPN = isValidTune(target_input);
            while (!validSPN)
            {
                cout << "Invalid input. Please enter a tune in valid SPN: " << endl;
                cin >> target_input;
                validSPN = isValidTune(target_input);
            }
            //prints out the rankings 
            printTuneRankings(first_input, second_input, third_input, target_input);
            break;
        }
        case 4: //loop ends, program stops 
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        //if invalid choice is entered from menu 
        default:
        {
            cout << "Invalid Input." << endl;
            break;
        }
        }
    }

    return 0;
}
