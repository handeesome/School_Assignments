#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char** argv)
{
	Critter c1;
	Critter c2("randomname");
	Critter c3("anothername", 2, 100, 30);
	Critter c4("anotherway", 2, 300);
	Critter c5("withThrist", 2, 3, 4, 5);

	c1.setHunger(2);
	c2.setHunger(2);
	c3.setHunger(2);
	c4.setHunger(2);

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
