#include <stdio.h>
void total_time(int mins[], int secs[], int n, int *sum_min, int *sum_sec){
    int min = 0, sec=0;
    for (int i = 0; i<n; i++){
        min += mins[i];
        sec += secs[i];
    }

    if (sec>59){
        min += sec/60;
        sec = sec%60;
    }

    *sum_min = min;
    *sum_sec = sec;
}
int main(){
    int mins[] = {1, 2, 3, 4};
    int secs[] = {10, 20, 30, 40};
    int n = 4;
    int summin, sumsec;
    int*sum_min = &summin;
    int*sum_sec = &sumsec;
    total_time(mins, secs, n, sum_min, sum_sec);

    printf("%d\n%d", summin, sumsec);
}
