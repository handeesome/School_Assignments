#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
	num = 1;
	den = 1;
}

Fraction::Fraction(int n, int d)
{
	int tmp_gcd = gcd(n, d);

	num = n / tmp_gcd;
	den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b)
{
	int tmp_gcd = 1;

	// Implement GCD of two numbers;

	return tmp_gcd;
}

int Fraction::lcm(int a, int b)
{
	return a * b / gcd(a, b);

}

void Fraction::print()
{
	std::cout << num << "/" << den << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Fraction &a)
{
    out << a.num << '/' << a.den << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction & a){
    std::cout << "Please enter the numerator: " << std::endl;
    in >> a.num;
    std::cout << "Please enter the denominator: " << std::endl;
    in >> a.den;
    return in;
}

Fraction Fraction::operator*(const Fraction& a){
    Fraction temp;
    temp.num = a.num * this->num;
    temp.den = a.den * this->den;

    return temp;
}

Fraction Fraction::operator/(const Fraction& a){
    Fraction temp;
    temp.num = this->num * a.den;
    temp.den = this->den * a.num;

    return temp;
}
