#include <iostream>
using namespace std;
/*#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"*/

#include "Area.cpp"
#include "Circle.cpp"
#include "Ring.cpp"
#include "Rectangle.cpp"
#include "Square.cpp"
/*
    ------------------------------------------------------------------------
    |                                                                      |
    |                          Area                                        |
    |    ---------------------------------------------------------         |
    |    |            |                                          |         |
    |    |            |               Circle                     |         |
    |    |            |                                          |         |
    |    | Rectangle  |    ---------------------------------     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |           Ring                |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    |                               |     |         |
    |    |            |    ---------------------------------     |         |
    |    ---------------------------------------------------------         |
    |                                                                      |
    ------------------------------------------------------------------------
 */
const int num_obj = 6;
int main() {
	Area *list[num_obj];						// (1)crate 6 objects of class Area, set name list
	int index = 0;								// (2)set int index to 0
	double sum_area = 0.0;						// (3)set double sum_area to 0.0
	double sum_perimeter = 0.0;
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4)create a ring object having blue color, 5 outer and 2 inner radius
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	list[0] = &blue_ring;						// (5)make the address of first object in the list to the blue ring
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	while (index < num_obj) {					// (7)loop 6 times
		(list[index])->getColor();
		double perimeter = list[index]->calcPeri();
		double area = list[index++]->calcArea();// (8)calculate every object's area
		sum_area += area;                       // and after every calculation, add index with one
		sum_perimeter += perimeter;
	}
	cout << "\nThe total area is "
			<< sum_area << " units " << endl;	// (9)print out the total area of 6 objects

    cout << "The total perimeter is "
            << sum_perimeter << " units " << endl;
	return 0;
}
