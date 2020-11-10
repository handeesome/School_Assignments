/*
CH-230-B
a1 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main() {
    float result; /* The result of the division */
    int a = 5;
    float b = 13.5;
    result = a/b;
    printf("The result is %f\n", result);
return 0;
}
/*
Comment: There are three amendments made, first "#" before include is missing, which causes the code not able to run.
And because 13.5 is not a integer so that "int" has to replace with "float" which makes decimals possible to calculate.
The correct result of "a/b" is a decimal number, so that "%d\n" has to be changed into "%f\n".
*/
