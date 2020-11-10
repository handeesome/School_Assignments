/*
CH-230-B
a13 p2.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include "Complex.cpp"
#include <fstream>

using namespace std;

int main() {
    ifstream file1 ("in1.txt");
    ifstream file2 ("in2.txt");
    int real, imag;
    char plus;
    file1 >> real >> plus >> imag;
    Complex one (real, imag);
    file2 >> real >> plus >> imag;
    Complex two (real, imag);

    Complex sum;
    sum = one + two;
    Complex difference;
    difference = one - two;
    Complex product;
    product = one * two;

    cout << "The sum, difference and product of two complex numbers are: \n";
    cout << sum << difference << product;

    ofstream file3 ("output.txt");
    file3 << sum << difference << product;

    file1.close();
    file2.close();
    file3.close();
    return 0;


}
