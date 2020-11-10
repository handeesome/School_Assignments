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
//make hunger between 0.0 and 1.0 internally
void Critter::setHunger(int newhunger) {
	hunger = (double)newhunger/10;
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
}

//when printing hunger, make it 100-percent
void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger*100 << "%." << endl;
	cout << "My boredom level is " << boredom << "." << endl;
	cout << "My height level is " << height << "." << endl;
}
