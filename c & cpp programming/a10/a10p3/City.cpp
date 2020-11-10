#include "City.h"

City::City(){
    name = mayor = "";
    inhabitants = area = 0;
}
City::City(string n, int i, string m, int a)
: name(n), inhabitants(i), mayor(m), area(a){}

void City::setName(string n){name = n;}
void City::setInhabitants(int i){inhabitants = i;}
void City::setMayor(string m){mayor = m;}
void City::setArea(int a){area = a;}

string City::getName(){return name;}
int City::getInhabitants(){return inhabitants;}
string City::getMayor(){return mayor;}
int City::getArea(){return area;}

void City::print(){
    cout << getName() << " has " << getInhabitants()
    << " inhabitants with area of " << getArea()
    << " km square and the mayor is " << getMayor() << endl;
}
