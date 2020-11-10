#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char* strdup(const char *s){
    size_t len = strlen(s);
    char* d = malloc(len*sizeof(char));
    return strncpy(d, s, len+1);
}
int main(int argc, char *argv[]){
    int i;
    for (i = 1; i < argc; i++) {
        puts(strdup(argv[i]));
    }
    return 0;
}
