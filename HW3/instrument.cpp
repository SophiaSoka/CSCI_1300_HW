#include <iostream>
using namespace std;
int main(){
    int category;
    int instrument;
    int price;
    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> category;
    //sort by category 
    switch (category)
    {
        //Brass category  
        case 1:
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> instrument;
            //sort by instrument, set price 
            switch(instrument)
            {
                case 1: 
                    price = 350;
                    break;
                case 2:
                    price = 400;
                    break;
                default:
                cout << "Please enter a valid input." << endl;
                return 0;
            }
            break;
        //Woodwind category 
        case 2:
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> instrument;
            //sort by instrument, set price 
            switch(instrument)
            {
                case 1: 
                    price = 325;
                    break;
                case 2:
                    price = 425;
                    break;
                default:
                cout << "Please enter a valid input." << endl;
                return 0;
            }
            break;
        //Percussion catagory
        case 3:
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> instrument;
            //sort by instrument, set price 
            switch(instrument)
            {
                case 1: 
                    price = 275;
                    break;
                case 2:
                    price = 200;
                    break;
                default:
                cout << "Please enter a valid input." << endl;
                return 0;
            }
            break;
        default:
            cout << "Please enter a valid input." << endl;
            return 0;

    }

    cout << "Your instrument will be $" << price << "." << endl;
    return 0;
}