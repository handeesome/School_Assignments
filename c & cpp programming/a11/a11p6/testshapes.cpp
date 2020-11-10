/*
CH-230-B
a11 p6.[c++]
Cenhan Du
cdu@jacobs-university.de
*/

#include "Shapes.h"

int main(int argc, char** argv) {

    Circle c("CIRCLE", 3, 4, 5);
    Rectangle r("RECTANGLE", 10, 10, 6, 7);
    Square s("SQUARE", -5, -5, 5);

    cout << c.getName() << " has " << c.perimeter() << " metres and " << c.area() << " metre squares!" << endl;
    cout << r.getName() << " has " << r.perimeter() << " metres and " << r.area() << " metre squares!" << endl;
    cout << s.getName() << " has " << s.perimeter() << " metres and " << s.area() << " metre squares!" << endl;

    return 0;
}
