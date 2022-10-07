#include <iostream> 
using namespace std;

int main(){

    int levels;
    int pos = 0;
    string alp = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    //takes input of number of levels, checks its postive 
    cout << "Enter the height: " << endl;
    cin >> levels;
    if (levels < 1){
        cout << "Invalid input." << endl;
        return 0;
    }
    string output;
    //runs for the amount of levels you want 
    //gets substring starting at postion and goes to a length 2 more than the previous 
    for (int i = 1; i <= levels; i++){
        output = alp.substr((pos % 26), ((i)*2 -1));
        cout << output << endl;
        pos += (i*2 -1);
    }

    return 0;
}