#include <iostream>
#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
    //make hunger double
private:  // data members are private
	std::string name;
	double hunger;
	int boredom;
	double height;
	double thirst;
	//thirst being added as double

public: // business logic methods are public
	// setter methods
	Critter();
	Critter(std::string name);
	Critter(std::string name, double hunger, int boredom, double height = 10);
	Critter(std::string name, double hunger, int boredom, double height, double thirst);
	//a new constructor with thirst as a parameter

	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setHeight(double height);
	void setThirst(double thirst);
	// getter method
	int getHunger();
	int getBoredom();
	double getHeight();
	double getThirst();
	// service method
	void print();

};
