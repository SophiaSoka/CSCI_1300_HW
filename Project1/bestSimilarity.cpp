// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 5 - Best Similarity

#include <iostream>
#include <iomanip>
#include <cassert>
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

/*
Algorithm: calculates the best possible tune similarity score of two tunes 
    1. Inputs two tunes, checks to make sure first tune is not smaller than second tune (if not, returns 0)
    2. Creats variables to keep track of best score, score loop is currently on and the length of the tune
    3. Loops through the larger tune and compares it to the traget tune
    4. Finds similarity score of the current substring and target and comapres it to the best score 
    5. If current score is greater than best score, best score is updated 
    6. Best score is then returned as a double
    Parameters: inputTune (string), targetTune (string)
    Returns: best similarty score of substring of theinputTune and target tune (double)
*/
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

//needed for assert statement for doubles 
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

int main(){
     // test 1, checking similar tunes with repeating decimal as score (0.666667)
    double result1 = bestSimilarity("E4D5B7G2E2", "D6G5G2");
    assert(doublesEqual(result1, 0.666667));
    // test 2, checking tunes when best score is negative (-0.333333)
    double result2 = bestSimilarity("F1E2C2D1A7B8D3", "F2A7C3");
    assert(doublesEqual(result2, -0.333333));
    // test 3, checking score that is invalid inputs due to lengths (0)
    double result3 = bestSimilarity("A2G7", "E9D2C4F1");
    assert(doublesEqual(result3, 0));
}
