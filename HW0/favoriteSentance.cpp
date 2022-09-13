#include <iostream>
#include <string> 

using namespace std;

int main(){
    //prompt the user to enter their favorite 
    string favorite_sentance;

    int num_words;

    //cout << "Please enter number of words in sentance";
    cout << "Please enter your favorite sentance: ";
    getline(cin, favorite_sentance);
    //cin >> favorite_sentance1 << >> num_words;

    cout << favorite_sentance << endl;

}