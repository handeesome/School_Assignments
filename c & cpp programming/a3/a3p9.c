/*
CH-230-B
a3 p9.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
double sum25(double v[], int n){
    double sum25 = v[2]+v[5];

    if (n<6){
        return -111;

    }

    return sum25;
}

int main(){
    int n;
    scanf("%d", &n);
    double v[n];
    for (int i=0; i<n; i++){
        scanf("%lf", &v[i]);
    }

    if(sum25(v, n)==-111){
        printf("One or both positions are invalid\n");
    }
    else {
        printf("sum=%lf\n", sum25(v, n));
    }

    return 0;
}
