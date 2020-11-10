/*
CH-230-B
a9 7.[c++]
Cenhan Du
cdu@jacobs-university.de
*/
#include <iostream>
using namespace std;
//returns the first positive and even element
int myfirst(int *num, int length){
    for (int i=0; i<length; i++){
        if (num[i]>0 && (num[i]%2)==0){
            return num[i];
        }
    }
    return -1;
}
//returns the first negative and whole element
double myfirst(double *num, int length){
    for (int i=0; i<length; i++){
        if (num[i]<0 && (num[i]-(int)num[i])==0){
            return num[i];
        }
    }
    return -1.1;
}
//determine whether a character is a consonant
int consonant (char c){
    switch (c){
        case 66 ... 68:
        case 70 ... 72:
        case 74 ... 78:
        case 80 ... 84:
        case 86 ... 90:
        case 98 ... 100:
        case 102 ... 104:
        case 106 ... 110:
        case 112 ... 116:
        case 118 ... 122:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
//returns the first consonant character element
char myfirst(char *c, int length){
    for (int i=0; i<length; i++){
        if (consonant(c[i])==1){
            return c[i];
        }
    }
    return '0';
}
int main(){
    int a[] = {1, 2, 3, 4, 5};
    double b[] = {1.1, 2.2, 3.3, 4.4, 5.5, -6};
    char c[] = "aeiouj";
//the exactly sizes of the arrays
    int loa = sizeof(a)/sizeof(int);
    int lob = sizeof(b)/sizeof(double);
    int loc = sizeof(c)/sizeof(char);

    cout << myfirst(a, loa) << endl << myfirst(b, lob) << endl
    << myfirst(c, loc) << endl;

    return 0;
}
