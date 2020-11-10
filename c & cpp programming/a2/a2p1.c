/*
CH-230-B
a2 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
int main(){
    double a, b;
    int c, d;
    char e, f;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    getchar();
    scanf("%c", &e);
    getchar();
    scanf("%c", &f);
    int sumofintegers = c+d;
    int productofintegers = c*d;
    int sumofchars = e+f;
    int productofchars = e*f;
    printf("sum of doubles=%lf\n", a+b);
    printf("difference of doubles=%lf\n", a-b);
    printf("square=%lf\n", a*a);
    printf("sum of integers=%d\n", sumofintegers);
    printf("product of integers=%d\n",productofintegers);
    printf("sum of chars=%d\n", sumofchars);
    printf("product of chars=%d\n", productofchars);
    printf("sum of chars=%c\n", sumofchars);
    printf("product of chars=%c\n", productofchars);

    return 0;
}
