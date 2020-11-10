#include "Person.h"
Person::Person(){
    name = eyecolour = "";
    age = weight = 0;
}

Person::Person(const string& n, int a, float w, string e)
 : name(n), age(a), weight(w), eyecolour(e){}

Person::Person(Person& a){
    name = a.getName();
    age = a.getAge();
    weight = a.getWeight();
    eyecolour = a.getEyecolour();
}

const void Person::setName(const string& n){name = n;}

void Person::setAge(int a){age = a;}

void Person::setWeight(float w){weight = w;}

const void Person::setEyecolour(const string e){eyecolour = e;}

string Person::getName(){return name;}

int Person::getAge(){return age;}

float Person::getWeight(){return weight;}

string Person::getEyecolour(){return eyecolour;}

void Person::print(){
    cout << getName() << " is " << getAge() << " years old with "
    << getEyecolour() << " eyes and is " << getWeight() << "kg." << endl;
}

