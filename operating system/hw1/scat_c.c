#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char c;
    int opt;
    int key = 1;

    while((opt=getopt(argc, argv, ":ls")) != -1){
        switch(opt){
        case 'l':
            key = 1;
            break;
        case 's':
            key = 2;
            break;
        case 'p':
            key =3;
            break;
        default:
            key = 1;
            break;
        }
    }
    if(key==1){
    printf("o");
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
    }else if(key==2){
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
    }else if(key==3){
        struct stat stat_buf;
        off_t offset = 0;
        int read_fd = open(argv[2], O_RDONLY);
        fstat(read_fd, &stat_buf);
        int write_fd = open(argv[3], O_WRONLY | O_CREAT, stat_buf.st_mode);
        sendfile (write_fd, read_fd, &offset, stat_buf.st_size);
        if(close(read_fd)<0){
            perror("c1");
            exit(1);
        }
        if(close(write_fd)<0){
            perror("c2");
            exit(1);
        }
    }
    return 0;
}

