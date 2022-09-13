#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // declare an int
    cout << "type two numbers" << endl;
     
    int first_int, second_int;
    cin >> first_int >> second_int;

    // divide one int by the other USING INTEGER DIVISION, print result
    cout << "The sum is " << first_int + second_int << endl;
    cout << "The difference is " << first_int - second_int << endl;
    cout << "The product is " << first_int*second_int << endl;
    cout << "The quoent is " << first_int/second_int << endl;
    // divie one int by the other USING FLOATING POINT DIVISION, print result
    cout << first_int / static_cast<float>(second_int) << endl;
    // print out remainder of dividing one int by the other (hint: modulo operator)



    return 0;
}