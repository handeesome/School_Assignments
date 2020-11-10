#include "TournamentMember.h"

string TournamentMember::location = "Bremen";//static property location is initialized as "Bremen"
                                             //of all of the objects
void TournamentMember::Changelocation(string nl) {
	location = nl;
}

TournamentMember::TournamentMember() {
	cout << "TournamentMember default constructor being called!" << endl;
}

TournamentMember::TournamentMember(const char fn[36], const char ln[36], const char b[11], double h, int a)
: height(h), age(a){
	strcpy(firstname, fn);
	strcpy(lastname, ln);
	strcpy(birth, b);
	cout << "TournamentMember parametric constructor being called!" << endl;
}

TournamentMember::TournamentMember(TournamentMember& a) {
	strcpy(firstname, a.getFirstName());
	strcpy(lastname, a.getLastName());
	strcpy(birth, a.getBirth());
	height = a.getHeight();
	age = a.getAge();
	cout << "TournamentMember copy constructor being called!" << endl;
}

TournamentMember::~TournamentMember() {
	cout << "TournamentMember destructor being called!" << endl;
}

void TournamentMember::print() {
	cout << firstname << lastname << " is from " << location << " who is born at "
		<< birth << " and is " << height << " and is " << age << " years old." << endl;
}

Player::Player() : score(0){
    cout << "Player default constructor being called!" << endl;
}

Player::Player(const char fn[36], const char ln[36], const char b[11]
               , double h, int a, int n, string p, string f)
               :TournamentMember(fn, ln, b, h, a), number(n), position(p), score(0), foot(f){
               cout << "Player parametric constructor being called!" << endl;
               }

Player::Player(Player& a){
    strcpy(firstname, a.getFirstName());
	strcpy(lastname, a.getLastName());
	strcpy(birth, a.getBirth());
    height = a.getHeight();
    age = a.getAge();
    number = a.getNumber();
    position = a.getPoisition();
    score = a.getScore();
    foot = a.getFoot();
    cout << "Player copy constructor being called!" << endl;
}

Player::~Player(){
    cout << "Player destructor being called!" << endl;
}

void Player::print(){
    cout << firstname << lastname << " is from " << location << " who is born at "
		<< birth << " and is " << height << " and is " << age << " years old." << endl;
    cout << "He is number " << number << " and is a " << position << " and a " << foot << "-footed." << endl;
    cout << "He has scored " << score << "!" << endl;
}

void Player::addscore(){
    score++;
}
