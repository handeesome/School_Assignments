#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char c;
    int opt;
    bool lORs;

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
        FILE* fp1;
        FILE* fp2;

        fp1 = fopen(argv[2], "r");
        fp2 = fopen(argv[3], "w");
        while(1){
            c = getc(fp1);
            if(c==EOF)
                break;
            putc(c, fp2);
        }
        fclose(fp1);
        fclose(fp2);
    }else{
        int fd1;
        int fd2;
        char buf[1];
        int num = 1;

        fd1 = open(argv[2], O_RDONLY);
        if(fd1<0){
            perror("r1");
            exit(1);
        }
        fd2 = open(argv[3], O_WRONLY | O_CREAT);
        if(fd2<0){
            perror("w1");
            exit(1);
        }
        while(num!=0){
            num = read(fd1, buf, 1);
            write(fd2, buf, 1);
        }
        if(close(fd1)<0){
            perror("c1");
            exit(1);
        }
        if(close(fd2)<0){
            perror("c2");
            exit(1);
        }
    }
    return 0;
}
