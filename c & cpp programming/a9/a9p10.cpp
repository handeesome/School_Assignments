/*
CH-230-B
a9 p10.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//replace vowels in a string to "_"
void replacevowel(string s){
    int i=0;
    while (s[i]!='\0'){
        if (s[i]=='a' || s[i]=='e' || s[i]=='i' ||
            s[i]=='o' || s[i]=='u'){
            s[i] = '_';
        }
        i++;
    }
    cout << s << endl;
}
int main(){
    string words[17] = {
        "computer", "television", "keyboard", "laptop", "mouse",
        "six", "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen", "seventeen"
    };

//let the player guess the changed random string
//if correct, print the times tried and ask whether play again
//if again, call main() function for another play
    int count = 0, randomnumber;
    srand ((unsigned)time(NULL));
    randomnumber = rand() % 17;
    replacevowel(words[randomnumber]);
    cout << "Please guess the word: " << endl;
    string temp;
    while(1){
        cin >> temp;
        count++;
        if(temp==words[randomnumber]){
            cout << "You guessed correctly in " << count << " times" << endl;
            cout << "Do you wish to play again?" <<endl;
            cin >> temp;
            if (temp=="quit"){
                exit(0);
            }
            else {
                main();
            }
        }
        else{
            cout << "You guessed incorrectly, please try again: " << endl;
        }
    }
    return 0;
}
