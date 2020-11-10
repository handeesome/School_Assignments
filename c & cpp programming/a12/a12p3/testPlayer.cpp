/*
CH-230-B
a12 p3.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "TournamentMember.h"
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
