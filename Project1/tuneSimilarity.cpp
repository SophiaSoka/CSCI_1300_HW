// CSCI1300 Fall 2022
// Author: Sophia Soka
// Recitation: 306 - Zachary Atkins
// Project 1 - Problem 4 - Tune Similarity
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

/*
Algorithm: calculates tune similarity based on three varibles
    1. Inputs two tunes, checks to make sure they're the same length (if not, returns 0)
    2. Loops through both tunes comparing each note of the same index
    3. Counts the number of notes with the same note, the same note and pitch and different notes with different pitches
    4. Divides the # of same_notes by # of total notes, then adds the # of same note and pitchs, and subtracts the number of different notes and pitches
    5. Prints the double of that equation, which is the similarity score
    Parameters: tune1 (string), tune2 (string)
    Returns: similarty score of the tunes (double)
*/
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

//needed for assert statement for doubles 
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}


int main()
{
    // test 1, checking similar tunes with repeating decimal as score (0.666667)
    double result1 = tuneSimilarity("G4E5D4", "G4F4D5");
    assert(doublesEqual(result1, 0.666667));
    // test 2, checking tunes with negative score (-4)
    double result2 = tuneSimilarity("A0B0C0D0", "D1C1B1A1");
    assert(doublesEqual(result2, -4));
    // test 3, checking score that is small and long (also checking edge cases) (0.333333)
    double result3 = tuneSimilarity("E5E5G5A6G5D5", "E5G5A6G5D5D5");
    assert(doublesEqual(result3, 0.333333));
    // test 4, checkings case with tunes that have different lengths (0)
    double result4 = tuneSimilarity("D5G2", "F7D1E4G4");
    assert(doublesEqual(result4, 0));
}

