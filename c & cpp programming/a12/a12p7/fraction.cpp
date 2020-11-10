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
//	int tmp_gcd = 1;

	// Implement GCD of two numbers;
	int temp1 = a%b;
	int temp2 = b;
	int tmp_gcd = 1;
    while (temp1!=0){
        tmp_gcd = temp1;
        temp1 = temp2 % temp1;
        temp2 = tmp_gcd;
    }

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

Fraction Fraction::operator+(const Fraction &a){
    Fraction temp;
    temp.den = lcm(this->den, a.den);
    temp.num = this->num*temp.den/this->den + a.num*temp.den/a.den;

    return temp;
}

Fraction Fraction::operator-(const Fraction &a){
    Fraction temp;
    temp.den = lcm(this->den, a.den);
    temp.num = this->num*temp.den/this->den - a.num*temp.den/a.den;

    return temp;
}

Fraction& Fraction::operator=(const Fraction &a){

    this->num = a.num;
    this->den = a.den;

    return *this;
}

bool Fraction::operator<(const Fraction &a){
    double first = (double)this->num / (double)this->den;
    double second = (double)a.num / (double)a.den;
    if (first < second){
        return true;
    }
    else{
        return false;
    }
}

bool Fraction::operator>(const Fraction &a){
    double first = (double)this->num / (double)this->den;
    double second = (double)a.num / (double)a.den;
    if (first > second){
        return true;
    }
    else{
        return false;
    }
}
