/*
CH-230-B
a3 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>

float convert (int cm){
    float km;
    km= (float)cm/100000;
    printf("Result of conversion: %f\n", km);
    return 0;
}

int main(){
    int cm;
    scanf("%d", &cm);

    convert(cm);

    return 0;
}
