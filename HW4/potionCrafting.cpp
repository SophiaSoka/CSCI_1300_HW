#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // declare all variables
    int potion;
    int honeycombs;
    int dandelions;
    int coal;
    int toadstools;
    bool start = true;
    
    // start
    while (start || !(potion == 1 || potion == 2)) 
    { 
        // prompt the user and get their input
        cout << "Select a potion crafting priority: " << endl;
        cout << "1. Minor Mana " << endl;
        cout << "2. Minor Healing " << endl;
        cin >> potion;
        // input validation 
        if (!(potion == 1 || potion == 2)){
            cout << "Invalid input."<< endl;;
        }
        else{
            start = false;
        }
    }
    //flag variables for each item 
    bool honey_pos = false; 
    bool dand_pos = false;
    bool coal_pos = false;
    bool toad_pos = false;

    //gets user input on the number of each item and checks if they're positive 
    while (!honey_pos){
        cout << "How many Honeycombs do you have? " << endl;
        cin >> honeycombs;
        if (honeycombs >= 0){
            honey_pos = true;
        }
        else {
            cout << "Invalid input. ";
        }
    }
    while ( !dand_pos){
        cout << "How many Dandelions do you have? " << endl;
        cin >> dandelions; 
        if (dandelions >=0){
            dand_pos = true;
        }
        else{
            cout << "Invalid input. ";
        }
    }
    while (!coal_pos){
        cout << "How many Coal do you have? " << endl;
        cin >> coal;
        if (coal >= 0){
            coal_pos = true;
        }
        else{
            cout << "Invalid input. ";
        }
    }
    while(!toad_pos){
        cout << "How many Toadstools do you have?  " << endl;
        cin >> toadstools;
        if (toadstools >= 0){
            toad_pos = true;
        }
        else{
            cout << "Invalid input. ";
        }
    }

    //variables to keep track of whats been checked and potions avaliable 
    int max_mana;
    int max_healing;
    bool flag = true;
    bool second_checked = false;

    
    while (flag){
        //minor mana is priority 
        if (potion == 1){
            //finding max that can be made 
            max_mana = honeycombs / 5;
            if ((dandelions/ 3) < max_mana){
                max_mana = dandelions / 3;
            }
            if (coal < max_mana){
                max_mana = coal;
            }
        
            //setting new values for items 
            honeycombs = honeycombs - (max_mana*5);
            dandelions = dandelions - (max_mana*3);
            coal = coal - (max_mana);
            //if the potion 2 is the preference 
            if (second_checked)
            {
                cout << "You can make " << max_healing << " Healing potion(s) and " << max_mana << " Mana potion(s)."<< endl;
                flag = false;
            }
            else //if potion 1 is priority 
            {
                potion = 2;
                second_checked = true;
            }

            
        }
        else if (potion == 2){
             //finding max that can be made 
            max_healing = honeycombs / 5;
            if (coal /2 < max_healing){
                max_healing = coal/2;
            }
            if (toadstools / 3 < max_healing){
                max_healing = toadstools / 3;
            }
        
            //setting new values for items 
            honeycombs = honeycombs - (max_healing*5);
            coal = coal - (max_healing*2);
            toadstools = toadstools - (max_healing*3);
            //if first was priority 
            if (second_checked)
            {
                cout << "You can make " << max_mana << " Mana potion(s) and " << max_healing << " Healing potion(s)."<< endl;
                flag = false;
            }
            else //if second is priority 
            {
                potion = 1;
                second_checked = true;
            }
        }
    }
    return 0;
}
