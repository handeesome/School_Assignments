#include <iostream>
#include "fraction.h"
using namespace std;

int main(void)
{
    Fraction a, b, c, d;
	cin >> a;
	cin >> b;

	c = a*b;
	d = a/b;

	cout << "Product:" << endl;
	cout << c;
	cout << "Quotient:" << endl;
	cout << d;
}
