/*
CH-230-B
a10 p3.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;

//class City with four properties, name, number of inhabitants,
//mayor, and area
//each property has one setter method and one getter method
//at last, the print method shows the properties
class City{
private:
    string name;
    int inhabitants;
    string mayor;
    int area;
public:
    City();
    City(string name, int inhabitants, string mayor, int area);

    void setName(string);
    void setInhabitants(int);
    void setMayor(string);
    void setArea(int);

    string getName();
    int getInhabitants();
    string getMayor();
    int getArea();

    void print();
};

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

main(){
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
