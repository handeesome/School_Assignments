#include "Critter.h"

using namespace std;

Critter::Critter(){
    name = "default_critter";
    height = 5;
    hunger = boredom = thirst = 0;
}

Critter::Critter(string n) : name(n){
    height = 5;
    hunger = boredom = thirst = 0;
}

Critter::Critter(string n, double h, int b, double he)
 : name(n), hunger(h), boredom(b), height(he), thirst(h){}

Critter::Critter(string n, double h, int b, double he, double t)
 : name(n), hunger(h), boredom(b), height(he), thirst(t){}

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

void Critter::setThirst(double newthirst){
    thirst = newthirst;
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

double Critter::getThirst(){
    return thirst;
}

//when printing hunger, make it 100-percent
void Critter::print() {
	cout << "I am " << name << ". My hunger level is " << hunger*100 << "%." << endl;
	cout << "My boredom level is " << boredom << "." << endl;
	cout << "My height level is " << height << "." << endl;
	cout << "My thirst level is " << thirst << "." <<endl;
	//added thirst in the print method
}
