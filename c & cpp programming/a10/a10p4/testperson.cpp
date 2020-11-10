/*
CH-230-B
a10 p4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "Person.h"

int main(){
    Person p1("p1", 10, 40, "blue");
    Person p2("p2", 20, 60, "black");
    Person p3("p3", 30, 80, "brown");
    Person p4("p4", 40, 100, "red");

    p1.print();
    p2.print();
    p3.print();
    p4.print();

    return 0;
}

