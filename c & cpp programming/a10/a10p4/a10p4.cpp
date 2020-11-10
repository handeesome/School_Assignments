/*
CH-230-B
a10 p4.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
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
    Person(string, int, float, string);

    void setName(string);
    void setAge(int);
    void setWeight(float);
    void setEyecolour(string);

    string getName();
    int getAge();
    float getWeight();
    string getEyecolour();

    void print();
};

Person::Person(){
    name = eyecolour = "";
    age = weight = 0;
}
Person::Person(string n, int a, float w, string e)
 : name(n), age(a), weight(w), eyecolour(e){}

void Person::setName(string n){name = n;}
void Person::setAge(int a){age = a;}
void Person::setWeight(float w){weight = w;}
void Person::setEyecolour(string e){eyecolour = e;}

string Person::getName(){return name;}
int Person::getAge(){return age;}
float Person::getWeight(){return weight;}
string Person::getEyecolour(){return eyecolour;}

void Person::print(){
    cout << getName() << " is " << getAge() << " years old with "
    << getEyecolour() << " eyes and is " << getWeight() << "kg." << endl;
}

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
