#include <stdio.h>
int main() {
double result; //∗ The result of our calculation ∗/
result = (3.0 + 1.0) / 5.0;
printf("The value of 4/5 is %lf\n", result);
return 0;
}
/*********************
 comment: the reason the result turns to 0 is that the result of input values had no decimal places, which makes 0.8 into 0.
 ********************/
