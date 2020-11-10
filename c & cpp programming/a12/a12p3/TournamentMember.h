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
