/*
CH-230-B
a4 p1.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    float x;
    float upperlimit, lowerlimit, stepsize;
    scanf("%f %f %f", &lowerlimit, &upperlimit, &stepsize);

    for (x=lowerlimit; x<=upperlimit; x+=stepsize){
        printf("%f %f %f\n", x, x *x * M_PI, x * 2 * M_PI);
    }
    return 0;
}

/*
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
    int num=0;
    float upperlimit=0,lowerlimit=0,step=0;
    scanf("%f %f %f",&lowerlimit,&upperlimit,&step);

    num=(upperlimit-lowerlimit)/step +1;
    for(int i=0;i<num;i++)
    {
        printf("%f %f %f\n",lowerlimit,lowerlimit*lowerlimit*M_PI,lowerlimit*2*M_PI);
        lowerlimit+=step;
    }

    return 0;
}
*/
