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
		TournamentMember();//default
		TournamentMember(const char firstname[36], const char lastname[36], const char birth[11], double height, int age);
		TournamentMember(TournamentMember&);//copy constructor
		~TournamentMember();//destructor
		void setFirstName(const char firstname[36]);//all setter and getter methods are
		void setLastName(const char lastname[36]);  //inline methods
		void setBirth(const char birth[11]);
		void setHeight(double height);
		void setAge(int age);
		char* getFirstName();
		char* getLastName();
		char* getBirth();
		double getHeight();
		int getAge();
		void print();//print out the properties of the member
		static void Changelocation(string newlocation);//static function to change the
};                                                     //static property location



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
