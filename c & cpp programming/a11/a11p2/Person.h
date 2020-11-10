#include <iostream>
using namespace std;

//this class has four properties, name, age, weight, and eye colour
//each property has a setter and getter method
//in Person class, the properties can be printed
class Person{
private:
    string name;
    int age;
    float weight;
    string eyecolour;
public:
    Person();
    Person(const string&, int, float, const string);
    Person(Person&);

    const void setName(const string&);
    void setAge(int);
    void setWeight(float);
    const void setEyecolour(const string);

    string getName();
    int getAge();
    float getWeight();
    string getEyecolour();

    void print();
};
