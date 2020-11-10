/*
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>
#include <iostream>
using namespace std;

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name
		void setName(std::string name);
		std::string getName()const;
};

class CenteredShape : public Shape {  // inherits from Shape
	private:
		double x,y;  // the center of the shape
	public:
		CenteredShape(const std::string&, double x, double y);  // usual three constructors
		CenteredShape();
		CenteredShape(const CenteredShape&);
		void move(double, double);	// moves the shape, i.e. it modifies it center
		void setX(double newx);
		void setY(double newy);
		double getX()const;
		double getY()const;
};

class RegularPolygon : public CenteredShape { // a regular polygon is a centered_shape with a number of edges
	private:
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double x, double y, int EdgesNumber);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);
		void setEdges(int newEdges);
		int getEdges()const;
};

class Circle : public CenteredShape {  // a Circle is a shape with a center and a radius
	private:
		double Radius;
	public:
		Circle(const std::string&, double x, double y, double r);
		Circle();
		Circle(const Circle&);
		void setRadius(double newRadius);
		double getRadius()const;
		double perimeter()const;
		double area()const;
};

class Rectangle : public RegularPolygon{
    private:
        double height, width;
    public:
        Rectangle();
        Rectangle(const std::string& n, double nx, double ny, double nwidth, double nheight);
        Rectangle(const Rectangle&);
        void setHeight(double);
        void setWidth(double);
        double getHeight()const;
        double getWidth()const;
        double perimeter()const;
        double area()const;
};

class Square : public Rectangle{
    private:
        double side;
    public:
        Square();
        Square(const std::string& n, double nx, double ny, double nside);
        Square(const Square&);
        void setSide(double);
        double getSide()const;
        double perimeter()const;
        double area()const;
};

#endif
