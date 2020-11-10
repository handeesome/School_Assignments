#include <stdio.h>
int main(){
    double a;
    float b;
    int c;
    scanf("%lf\n%f\n%d", &a, &b, &c);
    double result = a*b*c;
    printf("%lf\n", result);
    double* r_ptr = &result;
    *r_ptr += 5;
    printf("%lf\n%lf", result, *r_ptr);
}
