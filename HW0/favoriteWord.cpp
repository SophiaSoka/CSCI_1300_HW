#include <iostream>
#include <string> 

using namespace std;

int main(){
    //prompt the user to enter their favorite 
    string favorite_word;
    int num_letters;
    cout << "Please enter your favorite word: ";
    cout << "Please enter number of letters in new word";
    cin >> favorite_word >> num_letters;
    
    string new_word;
    new_word = favorite_word.substr(0, num_letters);

    int len = favorite_word.length();


    cout << "The word is " << favorite_word << endl;
    //cout << "The substring is " << sub_word << endl;
    cout << "The substring is " << new_word << endl;
}