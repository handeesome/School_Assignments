#include <iostream>
#include <string> // defines standard C++ string class

/* First C++ class */
class Critter
{
private:  // data members are private
	std::string name;
	int hunger;
	int boredom;
	double height;

public: // business logic methods are public
	// setter methods
	Critter();
	Critter(std::string name);
	Critter(std::string name, int hunger, int boredom, double height = 10);

	void setName(std::string& newname);
	void setHunger(int newhunger);
	void setBoredom(int newboredom);
	void setHeight(double height);
	// getter method
	int getHunger();
	int getBoredom();
	double getHeight();
	// service method
	void print();
};
