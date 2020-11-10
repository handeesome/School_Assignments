/*
CH-230-B
a9 6.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int tries = 0;
    int randomnumber;
    int guess;
    string name;
    cout << "Your name: " << endl;
    cin >> name;

    //init the rand() function
    srand ((unsigned)time(NULL));
    randomnumber = rand() % 100 +1;
    while (1){
        cout << "Take your guess between 1 and 100, " << name << ": " << endl;
        cin >> guess;
        tries++;
    //give the player hints depend on conditions
        if (guess > randomnumber){
            cout << "Too high" << endl;
        }
        else if (guess < randomnumber){
            cout << "Too low" << endl;
        }
        else{
            cout << "On the " << tries << "guess. Congratulations! " << name << "!" << endl;
            return 0;
        }
    }
}
