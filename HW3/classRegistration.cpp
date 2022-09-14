#include <iostream> 
using namespace std;

int main(){
    int department;
    int clas;
    int section;
//ask user for department 
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> department;
    if (department > 3 || department < 1)
    {
        cout << "Please enter a valid input." << endl;
        return 0;
    }
    //seperate by department 
    if (department == 1)
    {
        cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl;
        cin >> clas;
        //seperate by class
        if (clas == 1)
        {
            cout << "Select a section: (1)Section 100 (2)Section 200" << endl;
            cin >> section;
            //seperate by section 
            //print out the correct section 
            if (section == 1){
                cout << "You've been enrolled in Section 100 of Starting Computing!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 200 of Starting Computing!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        //Data Structures class 
        else if (clas == 2)
        {
            cout << "Select a section: (1)Section 101 (2)Section 201" << endl;
            cin >> section;
            //seperate by class 
            //print out the correct section 
            if (section == 1){
                cout << "You've been enrolled in Section 101 of Data Structures!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 201 of Data Structures!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        //Algorithms class 
        else if (clas == 3)
        {
            cout << "Select a section: (1)Section 102 (2)Section 202" << endl;
            cin >> section;
            //seperate by section 
            //prints correct section 
            if (section == 1){
                cout << "You've been enrolled in Section 102 of Algorithms!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 202 of Algorithms!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        else 
        {
            cout << "Please enter a valid input. " << endl;
            return 0;
        }
    }
    //Math Department  
    if (department == 2)
    {
        cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl;
        cin >> clas;
        //seperate by class
        if (clas == 1)
        {
            cout << "Select a section: (1)Section 400 (2)Section 500" << endl;
            cin >> section;
            //seperate by section 
            //print out correct section 
            if (section == 1){
                cout << "You've been enrolled in Section 400 of Calculus 1!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 500 of Calculus 1!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        //calc 2 class
        else if (clas == 2)
        {
            cout << "Select a section: (1)Section 401 (2)Section 501" << endl;
            cin >> section;
            //seperate by section 
            //print out section 
            if (section == 1){
                cout << "You've been enrolled in Section 401 of Calculus 2!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 501 of Calculus 2!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        //Linear Algabra class 
        else if (clas == 3)
        {
            cout << "Select a section: (1)Section 402 (2)Section 502" << endl;
            cin >> section;
            //seperate by section 
            //print out section 
            if (section == 1){
                cout << "You've been enrolled in Section 402 of Linear Algebra!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 502 of Linear Algebra!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        else 
        {
            cout << "Please enter a valid input. " << endl;
            return 0;
        }
    }
    //Science Department 
    if (department == 3)
    {
        cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl;
        cin >> clas;
        //seperate by class
        //Chem class
        if (clas == 1)
        {
            cout << "Select a section: (1)Section 700 (2)Section 800" << endl;
            cin >> section;
            //seperate by section 
            //print out section 
            if (section == 1){
                cout << "You've been enrolled in Section 700 of General Chemistry 1!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 800 of General Chemistry 1!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        //Physics class 
        else if (clas == 2)
        {
            cout << "Select a section: (1)Section 701 (2)Section 801" << endl;
            cin >> section;
            //seperate by section 
            //print section 
            if (section == 1){
                cout << "You've been enrolled in Section 701 of Physics 1!" << endl;
                return 0;
            }
            else if (section ==2){
                cout << "You've been enrolled in Section 801 of Physics 1!" << endl;
                return 0;
            }
            else {
                cout << "Please enter a valid input." << endl;
                return 0;
            }
        }
        
        else 
        {
            cout << "Please enter a valid input. " << endl;
            return 0;
        }
    }

}