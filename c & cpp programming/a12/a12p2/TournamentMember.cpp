#include "TournamentMember.h"

string TournamentMember::location = "Bremen";//static property location is initialized as "Bremen"
                                             //of all of the objects
void TournamentMember::Changelocation(string nl) {
	location = nl;
}

TournamentMember::TournamentMember() {
	cout << "Default constructor being called!" << endl;
}

TournamentMember::TournamentMember(const char fn[36], const char ln[36], const char b[11], double h, int a)
: height(h), age(a){
	strcpy(firstname, fn);
	strcpy(lastname, ln);
	strcpy(birth, b);
	cout << "Parametric constructor being called!" << endl;
}

TournamentMember::TournamentMember(TournamentMember& a) {
	strcpy(firstname, a.getFirstName());
	strcpy(lastname, a.getLastName());
	strcpy(birth, a.getBirth());
	height = a.getHeight();
	age = a.getAge();
	cout << "Copy constructor being called!" << endl;
}

TournamentMember::~TournamentMember() {
	cout << "Destructor being called!" << endl;
}

void TournamentMember::print() {
	cout << firstname << lastname << " is from " << location << " who is born at "
		<< birth << " and is " << height << " and is " << age << " years old." << endl;
}
