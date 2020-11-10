#include <stdio.h>
int main(){
    float a, b, h;
    printf("side of the square: ");
    scanf("%f", &a);
    printf("square area=%f\n", a*a);
    printf("length of the rectangle: ");
    scanf("%f", &a);
    printf("width of the rectangle: ");
    scanf("%f", &b);
    printf("rectangle area=%f\n", a*b);
    printf("base of the triangle: ");
    scanf("%f", &a);
    printf("height of the triangle: ");
    scanf("%f", &h);
    printf("triangle area=%f\n", a*h/2);
    printf("upper base of the trapezoid: ");
    scanf("%f", &a);
    printf("lower base of the trapezoid: ");
    scanf("%f", &b);
    printf("height of the trapezoid: ");
    scanf("%f", &h);
    printf("trapezoid area=%f", (a+b)*h/2);

    return 0;
}
