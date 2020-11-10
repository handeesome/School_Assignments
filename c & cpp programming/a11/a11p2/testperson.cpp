/*
CH-230-B
a10 p4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Person.h"

int main(){
    Person p1; //calls an empty constructor
    p1.setName("p1"); // set the properties by setter methods
    p1.setAge(10);
    p1.setWeight(40);
    p1.setEyecolour("white");

    Person p2("p2", 20, 60, "black"); // calls a parametric constructor

    Person p3(p1); // calls a copy constructor

    p1.print();
    p2.print();
    p3.print();

    return 0;
}

