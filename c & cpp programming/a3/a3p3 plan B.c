/*
CH-230-B
a3 p3.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>

float convert (int cm){
    float km;
    km= cm/100000.0;
    return km ;
    }

int main(){
    int cm;
    scanf("%d", &cm);
    printf("Result of conversion: %f\n", convert(cm));
    return 0;
}



