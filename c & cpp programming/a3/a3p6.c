/*
CH-230-B
a3 p6.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
float to_pounds(int kg, int g){
    float pounds = (kg + g/1000.0)*2.2 ;
    return pounds;
}
int main(){
    int kg, g;
    scanf("%d", &kg);
    scanf("%d", &g);
    printf("Result of conversion: %f\n", to_pounds(kg, g));

    return 0;
}
