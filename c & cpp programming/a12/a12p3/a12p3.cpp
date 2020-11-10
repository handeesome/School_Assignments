/*
CH-230-B
a12 p3.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
#include <cstring>
using namespace std;
class TournamentMember {
	protected:
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

string TournamentMember::location = "Bremen";//static property location is initialized as "Bremen"
                                             //of all of the objects
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

class Player : public TournamentMember{
    private:
        int number;
        string position;
        int score;
        string foot;
    public:
        void setNumber(int number); //all the setter and getter methods are inlined
        void setPosition(string position);
        void setFoot(string foot);
        int getNumber()const;
        string getPoisition()const;
        int getScore()const;
        string getFoot()const;
        Player();//default and parametric constructors
        Player(const char firstname[36], const char lastname[36], const char birth[11]
               , double height, int age, int number, string position, string foot);
        Player(Player&);//copy constructor
        ~Player();//destructor
        void print();//no need of virtual in this case
        void addscore();//add one to the score
};


inline void Player::setNumber(int n){
    number = n;
}

inline void Player::setPosition(string p){
    position = p;
}

inline void Player::setFoot(string f){
    foot = f;
}

inline int Player::getNumber()const{
    return number;
}

inline string Player::getPoisition()const{
    return position;
}

inline int Player::getScore()const{
    return score;
}

inline string Player::getFoot()const{
    return foot;
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


int main() {
	Player a;
	a.setAge(18);
	a.setBirth("2001-1-1");
	a.setFirstName("afirst");
	a.setLastName("alast");
	a.setHeight(180);
	a.setNumber(1);
	a.setPosition("Goalkeeper");
	a.setFoot("right");
	a.addscore();
	a.addscore();

	Player b("bfirst", "blast", "2000-1-1", 190, 19, 2, "Defender", "right");
	b.addscore();

	Player c("cfirst", "clast", "1999-1-1", 200, 20, 3, "Midfielder", "left");

	Player::Changelocation("Hamburg");


	a.print();
	b.print();
	c.print();
	return 0;
}
