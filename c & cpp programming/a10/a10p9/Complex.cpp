#include <iostream>
#include <cmath>                      //needed for sqrt
#include "Complex.h"

using namespace std;  // for cout

Complex::Complex() {  // sets everything to 0
	real = imag = 0;
}
Complex::Complex(float r, float i) {  // initializes it to a given couple.
									  // Please note that here it is
	real = r;                         // not necessary to replicate the default value for the second parameter
	imag = i;
}

Complex::Complex(const Complex& oldcomplex){
    real = oldcomplex.real;
    imag = oldcomplex.imag;
}

Complex::~Complex(){
}

void Complex::setReal(float newreal){
    real = newreal;
}

void Complex::setImag(float newimag){
    imag = newimag;
}

float Complex::getReal(){
    return real;
}

float Complex::getImag(){
    return imag;
}

Complex Complex::conjugation(){
    Complex temp;

    temp.real = real;
    temp.imag = imag*-1;

    return temp;
}

Complex Complex::add(Complex a){
    Complex temp;

    if (a.imag || imag){
        temp.real = a.real + real;
        temp.imag = a.imag + imag;
    }
    else{
        temp.real = a.real + real;
    }

    return temp;
}

Complex Complex::subtract(Complex a){
    Complex temp;

    if (a.imag || imag){
        temp.real = real - a.real;
        temp.imag = imag - a.imag;
    }
    else{
        temp.real = real - a.real;
    }

    return temp;
}

Complex Complex::multiply(Complex a){
    Complex temp;

    if (a.imag || imag){
        temp.real = a.real * real - a.imag * imag;
        temp.imag = a.imag * real + a.real * imag;
    }
    else{
        temp.real = a.real * real;
    }

    return temp;
}

void Complex::print() {               // prints data to screen via cout
	if (imag) {
		cout << noshowpos << real << showpos << imag << "i" << endl;
	} else {
		cout << noshowpos << real << showpos << endl;
	}
}


