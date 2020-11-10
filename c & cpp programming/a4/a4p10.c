/*
CH-230-B
a4 p10.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#include <math.h>
void proddivpowinv(float a, float b, float *prod, float *div, float *pwr, float *invb){
    *prod = a * b;
    *div = a/b;
    *pwr = pow(a, b);
    *invb = 1 /b;
}
int main(){
    float a, b, prod, div, pwr, invb;
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);

    proddivpowinv(a, b, &prod, &div, &pwr, &invb);
    printf("a: %f\n", a);
    printf("b: %f\n", b);
    printf("product of a and b: %f\n", prod);
    printf("a divide by b: %f\n", div);
    printf("a to the power of b: %f\n", pwr);
    printf("1 over b: %f\n", invb);

    return 0;
}
