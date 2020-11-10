/*
CH-230-B
a11 p5.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Creature.h"

//dynamically create sub-classes with pointers and delete afterwards
int main()
{
    bool b = true;
    string a;
    while(b){
        cout << "Enter 'wizard' 'Flee' 'Crocodile' or 'quit':" << endl;
        cin >> a;
        if (a=="wizard"){
            Wizard* w = new Wizard;
            w->run();
            w->hover();
            delete w;
        }
        if (a=="Flee"){
            Flee* f = new Flee;
            f->run();
            f->jump();
            delete f;
        }
        if(a=="Crocodile"){
            Crocodile* c = new Crocodile;
            c->run();
            c->swim();
            delete c;
        }
        if(a=="quit"){
            b = false;
        }
    }

    return 0;
}
