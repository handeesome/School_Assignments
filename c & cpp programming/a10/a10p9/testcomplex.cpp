/*
CH-230-B
a10 p9.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    float real, imag;

	Complex c1, c2;
	cout << "Real part of first complex number: ";
	cin >> real;
	c1.setReal(real);
	cout << "Imag part: ";
	cin >> imag;
	c1.setImag(imag);
	cout << "Real part of second complex number: ";
	cin >> real;
	c2.setReal(real);
	cout << "Imag part: ";
	cin >> imag;
	c2.setImag(imag);

	Complex conjugate = c1.conjugation();
	cout << "conjugate: " << endl;
	conjugate.print();
	Complex sum = c1.add(c2);
	cout << "sum: " << endl;
	sum.print();
	Complex difference = c1.subtract(c2);
	cout << "difference: " << endl;
	difference.print();
	Complex product = c1.multiply(c2);
	cout << "product: " << endl;
	product.print();

	return 0;
}
