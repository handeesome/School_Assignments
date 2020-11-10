#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(NULL));              //seeding with local time

    set<int> s;
    for(int i=0; i<6; i++)
        s.insert( (rand()%49)+1 );  //insert random number into set

    set<int>::iterator it;
    for(it=s.begin(); it!=s.end();it++) //print the set in ascending order
        cout << *it << ' ';

    return 0;
}

