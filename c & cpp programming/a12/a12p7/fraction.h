// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1
	void print();				// prints it to the screen

    friend std::ostream& operator<<(std::ostream& out, const Fraction& a);//operator overloading <<, print out
    friend std::istream& operator>>(std::istream& in, Fraction & a);//operator overloading, cin
    Fraction operator*(const Fraction& a);//operator overloading, add fractions
    Fraction operator/(const Fraction& a);//operator overloading, divide fractions
    Fraction operator+(const Fraction& a);//operator overloading, add fractions
    Fraction operator-(const Fraction& a);//operator overloading, subtract fractions
    Fraction& operator=(const Fraction& a);//operator overloading, assign fractions
    bool operator<(const Fraction& a);//operator overloading, compare
    bool operator>(const Fraction& a);//operator overloading, compare

};



#endif /* FRACTION_H_ */
