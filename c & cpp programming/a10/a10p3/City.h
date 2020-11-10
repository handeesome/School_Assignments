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
