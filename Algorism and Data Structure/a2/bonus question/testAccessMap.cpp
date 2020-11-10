#include "Access.h"

int main(){
    Access a;

    a.activate(1234, 1);
    a.activate(9999, 5);
    a.activate(9876, 9);           //activate 3 pass codes

    int tempcode;

    while(1){
        cout << "Please enter an access code: " << endl;
        cin >> tempcode;
        if(!a.isactive(tempcode, 5))
            cout << "The door fails to open!";              //ask the user to open the door
        else{
            cout << "The door opens successfully!" << endl;
            break;
        }
    }

    a.deactivate(tempcode);                 //remove the corrected pass code
    a.deactivate(9999);
    a.activate(9999, 8);                     //change 9999 to access 8
    a.activate(1111, 7);                       //activate 1111

    while(1){
        cout << "Please enter an access code: " << endl;
        cin >> tempcode;
        if(!a.isactive(tempcode, 7))
            cout << "The door fails to open!";
        else{
            cout << "The door opens successfully!" << endl;     //ask the user to open the door again
            break;
        }
    }
    return 0;
}
