#include <iostream>
#include "Square.h"

Square::Square(const char *n, double a)
        : Rectangle(n, a, a), sidelength(a){}

Square::~Square(){}

double Square::calcArea() const{
    std::cout << "calcArea of Square...";
	return sidelength*sidelength;
}

double Square::calcPeri() const{
    std::cout << "calcPeri of Square...";
    return 4*sidelength;
}
