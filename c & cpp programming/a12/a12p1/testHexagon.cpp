/*
CH-230-B
a12 p1.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Shapes.h"
#include <iostream>

int main(){
    Hexagon blue("blue", 1, 1, 9, "blue");
    Hexagon green("green", 1, 2, 15, "green");
    Hexagon copyone(green);

    cout << "The perimeter of the blue hexagon is: " << blue.perimeter()
    << " and the area is: " << blue.area() << endl;
    cout << "The perimeter of the green hexagon is: " << green.perimeter()
    << " and the area is: " << green.area() << endl;
    cout << "The perimeter of the copy hexagon is: " << copyone.perimeter()
    << " and the area is: " << copyone.area() << endl;
}
