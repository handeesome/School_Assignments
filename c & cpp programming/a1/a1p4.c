/*
CH-230-B
a1 p4.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
    int main(){
        float x=17;
        float y=4;
        int sum=x+y;
        int product=x*y;
        int difference=x-y;
        float division=x/y;
        int remainder=(int)x%(int)y;
        printf ("x=%.0f\n",x);
        printf ("y=%.0f\n",y);
        printf ("sum=%d\n", sum);
        printf ("product=%d\n", product);
        printf ("difference=%d\n", difference);
        printf ("division=%f\n", division);
        printf ("remainder of division=%d\n", remainder);
        return 0;
}
