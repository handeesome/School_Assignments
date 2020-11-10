#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char c;
    int opt;
    bool lORs = true;

    while((opt=getopt(argc, argv, ":ls")) != -1){
        switch(opt){
        case 'l':
            lORs = true;
            break;
        case 's':
            lORs = false;
            break;
        default:
            lORs = true;
            break;
        }
    }
    if(lORs){
        while(c!='\n'){
            c = getc(stdin);
            putc(c, stdout);
        }
    }else{
        while(1){
            read(0, stdin, 1);
            write(1, stdin, 1);
        }
    }
    return 0;
}
