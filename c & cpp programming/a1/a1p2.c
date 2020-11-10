/*
CH-230-B
a1 p2.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main() {
	int result; //∗ The result of our calculation ∗/
	result = (2 + 7) * 9 / 3;
	printf("The result is %d\n", result);
	return 0;
}

/*******************
 comment: because the result is not printed out, %d\n will print out a random number, so result has to be in the printf.
 ******************/