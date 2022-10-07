#include <iostream> 
using namespace std;

int main(){
    //main variables 
    string full_DNA;
    string fragment;
    char letter;
    //enter DNA, checks that its valid 
    cout << "Enter the DNA Sequence: " << endl;
    cin >> full_DNA;
    for (int i = 0; i < full_DNA.length(); i++){
        letter = full_DNA[i];
        if (!(letter == 'A' || letter == 'C' || letter == 'G' || letter == 'T')){
            cout << "This is not a valid DNA sequence." << endl;
            return 0;
        }
    }
    //enter fragment, checks that its valid 
    cout << "Enter the DNA fragment to be searched: " << endl;
    cin >> fragment;
    for (int i = 0; i < fragment.length(); i++){
        letter = fragment[i];
        if (!(letter == 'A' || letter == 'C' || letter == 'G' || letter == 'T')){
            cout << "This is not a valid DNA sequence" << endl;
            return 0;
        }
    }

    //loops through DNA to look for fragment, counts amounts of times its found 
    int frag_len = fragment.length();
    int count = 0;
    for (int i = 0; i <= (full_DNA.length() - frag_len); i++){
        if (full_DNA.substr(i, frag_len) == fragment){
            count = count + 1;
        }
    }
    cout << "Number of occurrences: " << count << endl;
    return 0;   
}