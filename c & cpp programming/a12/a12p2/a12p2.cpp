  /*
CH-230-B
a12 p2.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <cstring>
using namespace std;
class TournamentMember {
	private:
		static string location;
		char firstname[36];
		char lastname[36];
		char birth[11];
		double height;
		int age;
	public:
		TournamentMember();
		TournamentMember(const char firstname[36], const char lastname[36], const char birth[11], double height, int age);
		TournamentMember(TournamentMember&);
		~TournamentMember();
		void setFirstName(const char firstname[36]);
		void setLastName(const char lastname[36]);
		void setBirth(const char birth[11]);
		void setHeight(double height);
		void setAge(int age);
		char* getFirstName();
		char* getLastName();
		char* getBirth();
		double getHeight();
		int getAge();
		void print();
		static void Changelocation(string newlocation);
};

string TournamentMember::location = "Bremen";

void TournamentMember::Changelocation(string nl) {
	location = nl;
}

inline void TournamentMember::setFirstName(const char fn[36]) {
	strcpy(firstname, fn);
}

inline void TournamentMember::setLastName(const char ln[36]) {
	strcpy(lastname, ln);
}

inline void TournamentMember::setBirth(const char b[11]) {
	strcpy(birth, b);
}

inline void TournamentMember::setHeight(double h) {
	height = h;
}

inline void TournamentMember::setAge(int a) {
	age = a;
}

inline char* TournamentMember::getFirstName(){
	return firstname;
}

inline char* TournamentMember::getLastName(){
	return lastname;
}

inline char* TournamentMember::getBirth(){
	return birth;
}

inline double TournamentMember::getHeight(){
	return height;
}

inline int TournamentMember::getAge(){
	return age;
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

int main() {
	TournamentMember a;
	a.setAge(18);
	a.setBirth("2001-1-1");
	a.setFirstName("first");
	a.setLastName("last");
	a.setHeight(180);
	TournamentMember b("bfirst", "blast", "2000-1-1", 190, 19);
	TournamentMember c(b);

	a.print();
	b.print();
	c.print();
	return 0;
}
