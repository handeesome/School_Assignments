/*
CH-230-B
a12 p2.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include "TournamentMember.h"
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
