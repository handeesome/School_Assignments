/*
CH-230-B
a3 p7.[c]
Cenhan Du
cdu@jacobs-university.de
*/
#include <stdio.h>
void print_form(int n, int m, char c){
    int a, b;
//compare first number with the second, start printing from the smaller number
//after every number reaches, start a new line, keep printing until reaches n+m-1
//so if two numbers are 4 and 3, print 3 char 3, and then next line, so on.
    if (n>m){
        for (a=m; a< n+m; a++){
            for (b=1; b<=a; b++){
                printf("%c", c);
            }
            printf("\n");

        }
    }
    else{
        for (a=n; a< n+m; a++){
            for (b=1; b<=a; b++){
                printf("%c", c);
            }
            printf("\n");

        }
    }
}

int main(){
    int n, m;
    char c;

    scanf("%d\n%d", &n, &m);
    getchar();
    scanf("%c", &c);
//use the written function, which prints the form automatically.
    print_form(n, m, c);

    return 0;
}
