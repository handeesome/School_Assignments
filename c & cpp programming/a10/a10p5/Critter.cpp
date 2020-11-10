#include "Critter.h"

using namespace std;

Critter::Critter(){
    name = "default_critter";
    height = 5;
    hunger = boredom = 0;
}

Critter::Critter(string n) : name(n){
    height = 5;
    hunger = boredom = 0;
}

Critter::Critter(string n, int h, int b, double he)
 : name(n), hunger(h), boredom(b), height(he){}

void Critter::setName(string& newname) {
	name = newname;
}

void Critter::setHunger(int newhunger) {
	hunger = newhunger;
}

void Critter::setBoredom(int newboredom) {
	boredom = newboredom;
}

void Critter::setHeight(double newheight) {
	height = newheight;
}

int Critter::getHunger() {
	return hunger;
}

int Critter::getBoredom() {
	return boredom;
}

double Critter::getHeight() {
	return height;
}zzz

void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
	cout << "My boredom level is " << boredom << "." << endl;
	cout << "My height level is " << height << "." << endl;
}
