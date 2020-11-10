#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool check(char* password){
    int length = strlen(password);
    if(length<8){
        return false;
    }
    int count = 0;
    for(int i=0; i<length; i++){
        if(password[i]>=48 && password[i]<=57){
            count++;
        }
    }
    if(count>2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char* a= "ducenh223an";
    bool TOF = check(a);
    if(TOF){
        printf("true");
    }
    else
        printf("false");
}
