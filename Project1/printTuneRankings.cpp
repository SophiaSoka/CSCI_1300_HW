// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 6 -  Print Tune Rankings

#include <iostream>
#include <iomanip>

using namespace std;

bool isValidNote(string note)
{
    // checks if the length is correct
    bool output;
    if (note.length() == 2)
    {
        // checks the first part is a correct letter and the second part if a correct number based on ASCII number
        if ((note[0] >= 65 && note[0] <= 71) && (note[1] >= 48 && note[1] <= 57))
        {
            return true;
        }
    }
    // if length != 2, or either index doesn't pass test cases
    return false;
}

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
    // calculated the correct score based on the tracking variables calculated above
    double output = (double)(same_note / notes) + same_pitch - diff_note;
    return output;
}

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

/*
Algorithm: calculates the best possible tune similarity score of two tunes 
    1. Inputs three tunes to be compared to the fourth target tune
    2. Creats three variables with the best similarity score for each tune compared to the target 
    3. Creats three tracks variables (strings) that will recored wihich tunes are in what order 
    4. Compares the similarity scores and assigns them the correct ranking 
    5. Prints out the ranking  
    Parameters: tune1 (string), tune2 (string), tune3(string), targetTune (string)
    Returns: no return (does print out ranking to termial)
*/
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

int main(){
    //expected 1, 2, 3
    printTuneRankings("D3D4", "E3D4", "D3F4", "A7");
    //expected 2, 3, 1
    printTuneRankings("C2E7", "D4B3", "A4D1", "A4B7");
    //expected 2, 1, 3
    printTuneRankings("B8", "C8", "A7", "C8");
    //expected 3, 1, 2
    printTuneRankings("C2E7", "D4", "A4D1", "A4B7");
    //expected 3, 2, 1
    printTuneRankings("F4B2E6", "A1", "B6G2E4", "B7G4");

    return 0;
}
