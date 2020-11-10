#include <iostream>
#include "fraction.h"
using namespace std;

int main(void)
{
    Fraction a, b, c, d;
	cin >> a;
	cin >> b;

	cout << "The greater fraction: " << endl;
	if(a>b)
        cout << a;
    else
        cout << b;

    c = a+b;
    d = a-b;

	cout << "Sum:" << endl;
	cout << c;
	cout << "Difference:" << endl;
	cout << d;

}
