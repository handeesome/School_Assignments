// please refer to shapes.h for methods documentation

#include <iostream>
#include <math.h>
#include "Shapes.h"

using namespace std;

Shape::Shape(const string& n) : name(n) {
}

Shape::Shape():name("no name"){}

Shape::Shape(const Shape& a){
    name = a.getName();
}

void Shape::printName() const {
	cout << name << endl;
}
void Shape::setName(string n){
    name = n;
}

string Shape::getName()const{
    return name;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

CenteredShape::CenteredShape() : Shape(), x(0), y(0){}

CenteredShape::CenteredShape(const CenteredShape& a){
    setName(a.getName());
    x = a.getX();
    y = a.getY();
}

void CenteredShape::move(double nx, double ny){
    x = x+nx;
    y = y+ny;
}

void CenteredShape::setX(double nx){
    x = nx;
}

void CenteredShape::setY(double ny){y = ny;}

double CenteredShape::getX()const{return x;}

double CenteredShape::getY()const{return y;}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny)
{
	EdgesNumber = nl;
}

RegularPolygon::RegularPolygon() : CenteredShape(), EdgesNumber(0){}

RegularPolygon::RegularPolygon(const RegularPolygon& a){
    setName(a.getName());
    setX(a.getX());
    setY(a.getY());
    EdgesNumber = a.getEdges();
}

void RegularPolygon::setEdges(int nE){EdgesNumber = nE;}

int RegularPolygon::getEdges()const{return EdgesNumber;}

Circle::Circle(const string& n, double nx, double ny, double r) :
  CenteredShape(n,nx,ny)
{
	Radius = r;
}

Circle::Circle() : CenteredShape(), Radius(0){}

Circle::Circle(const Circle& a){
    setName(a.getName());
    setX(a.getX());
    setY(a.getY());
    Radius = a.getRadius();
}

void Circle::setRadius(double nR){Radius = nR;}

double Circle::getRadius()const{return Radius;}

double Circle::perimeter()const{return 2*(M_PI * Radius);}

double Circle::area()const{return M_PI*(Radius*Radius);}

Rectangle::Rectangle() : RegularPolygon(), height(0), width(0){}

Rectangle::Rectangle(const string& n, double nx, double ny, double nwidth, double nheight)
: RegularPolygon(n, nx, ny, 4){
    height = nheight;
    width = nwidth;
}

Rectangle::Rectangle(const Rectangle& a){
    setName(a.getName());
    setX(a.getX());
    setY(a.getY());
    height = getHeight();
    width = getWidth();
}

void Rectangle::setHeight(double nH){height = nH;}

void Rectangle::setWidth(double nW){width = nW;}

double Rectangle::getHeight()const{return height;}

double Rectangle::getWidth()const{return width;}

double Rectangle::perimeter()const{return 2*(height+width);}

double Rectangle::area()const{return height*width;}

Square::Square() : Rectangle(), side(0){}

Square::Square(const string& n, double nx, double ny, double nside) :
    Rectangle(n, nx, ny, nside, nside){side = nside;}

Square::Square(const Square& a){
    setName(a.getName());
    setX(a.getX());
    setY(a.getY());
    side = a.getSide();
}

void Square::setSide(double nS){side = nS;}

double Square::getSide()const{return side;}

double Square::perimeter()const{return 4*side;}

double Square::area()const{return side*side;}
