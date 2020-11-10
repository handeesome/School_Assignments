#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c1;
	c1.setHunger(2);
	Critter c2("randomname");
	c2.setHunger(2);
	Critter c3("anothername", 2, 100, 30);
	Critter c4("anotherway", 2, 300);zz

	cout << "Instance one: " << endl;
	c1.print();
    cout << "Instance two: " << endl;
    c2.print();
	cout << "Instance three: " << endl;
	c3.print();
	cout << "Instance four: " << endl;
	c4.print();

    return 0;
}
