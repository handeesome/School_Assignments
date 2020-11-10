/*
CH-230-B
a10 p3.[c++]
Cenhan Du
cdu@jacobs-university.de
*/

#include "City.h"

int main(){
    City Bremen;
    Bremen.setName("Bremen");
    Bremen.setInhabitants(1000);
    Bremen.setMayor("John");
    Bremen.setArea(10000);

    City Paris("Paris", 1000, "Doe", 100000);

    City London;

    Bremen.print();
    Paris.print();
    London.print();

    return 0;
}
