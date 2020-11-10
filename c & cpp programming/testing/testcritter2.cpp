#include <iostream>
#include <cstdlib>
//#include "Critter2.h"
#include "Critter2.cpp"

using namespace std;

int main(int argc, char** argv)
{
    string name;
    int hungry;
    int boredom;
    float height;
    cin >> name >> hungry >> boredom >> height;
	Critter b(name, hungry);
	b.print();

	Critter *a;
    	a = new Critter();
    	a->setName(name);
    	a->setHunger(hungry);
	a->print();

	Critter *c;
    	c = new Critter(name, hungry, boredom, height);
	c->print();

	Critter *d;
	d->print(); // will create segmentation fault!
	return 0;
}
