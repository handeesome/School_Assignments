/*
CH-230-B
a11 p4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Creature.h"

int main()
{
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    Wizard wi(100);
    wi.run();
    wi.hover();

    cout << "\nCreating a Flee.\n";
    Flee f;
    f.run();
    f.setDis(20);
    f.jump();

    Flee fl(250);
    fl.run();
    fl.jump();

    cout << "\nCreating a Crocodile.\n";
    Crocodile cr;
    cr.run();
    cr.swim();

    Crocodile cro(1314);
    cro.run();
    cro.swim();

    return 0;
}
