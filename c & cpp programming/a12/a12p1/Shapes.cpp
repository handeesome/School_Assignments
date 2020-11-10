// please refer to shapes.h for methods documentation

#include <iostream>
#include "Shapes.h"
#include <cmath>

using namespace std;

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny)
{
	EdgesNumber = nl;
}

Circle::Circle(const string& n, double nx, double ny, double r) :
  CenteredShape(n,nx,ny)
{
	Radius = r;
}

Hexagon::Hexagon(const string& n, double nx, double ny, int s, string c)
 : RegularPolygon(n, nx, ny, 6), side(s), color(c){}

Hexagon::Hexagon(Hexagon& a) : RegularPolygon(a.name, a.x, a.y, 6){

    side = a.getSide();
    color = a.getColor();
}

Hexagon::~Hexagon(){}

void Hexagon::setSide(int s){
    side = s;
}

void Hexagon::setColor(string c){
    color = c;
}

int Hexagon::getSide()const{
    return side;
}

string Hexagon::getColor()const{
    return color;
}

int Hexagon::perimeter()const{
    return 6*side;
}

double Hexagon::area()const{
    double area = 3*sqrt(3)*side*side/2;
    return area;
}

