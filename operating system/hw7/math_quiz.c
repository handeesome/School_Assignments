#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define BUFSIZE 50
char* question;
char* Answer;

char* readall(int fd){
    int eof = 1;
    char *buf = (char *)malloc(sizeof(char)*BUFSIZE);
    char *result = (char *)malloc(sizeof(char)*BUFSIZE*4);
    eof = read(fd, buf, BUFSIZE);
    buf[eof] = '\0';
    strcpy(result, buf);
    while(eof!=0){
        eof = read(fd, buf, BUFSIZE);
        buf[eof] = '\0';
        strcat(result, buf);
    }
    free(buf);
    return result;
}

char* fetch(){
    int fd1[2]; //pipe
    pid_t p;
    char* argument_list[] = {"curl", "-s", "http://numbersapi.com/random/math?min=1&max=100&fragment&json", NULL};
    char* data;
    int  stdout_bk; //is fd for stdout backup
    stdout_bk = dup(fileno(stdout));

    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        exit(1);
    }
    p = fork();
    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        exit(1);
    }
    //parent process
    else if (p>0){
        close(fd1[1]);
        data = readall(fd1[0]);
        dup2(stdout_bk, fileno(stdout));//restore
        kill(p,SIGKILL);
        return data;
    }
    //child process
    else{
        close(fd1[0]);
        dup2(fd1[1], fileno(stdout));
        execvp("curl", argument_list);
    }
}
void getText(){
    char* data = fetch();
    char* delim = "\"";
	char *ptr = strtok(data, delim);
    int length;
    int i=0;
	while (ptr != NULL)
	{
        if(i==3)
            question=ptr;
        if(i==6)
            Answer=ptr;
        i++;
		ptr = strtok(NULL, delim);
	}
    ptr = strtok(Answer, ":,");
    Answer = ptr;
}
unsigned play(unsigned n, unsigned score, char *text, long answer){
    int receiveScore = 8;
    long receiveAnswer;
    printf("Q%d: %s?\n", n, text);
    for(int i=0; i<4; i++){
        printf("%d pt> ", receiveScore);
        scanf("%ld", &receiveAnswer);
        if(receiveAnswer!=answer){
            if(receiveAnswer>answer){
                printf("Too large, ");
            }else{
                printf("Too small, ");
            }
            receiveScore /=2;
            if(receiveScore==0){
                printf("The correct answer was %ld.\n", answer);
            }else{
                printf("try again.\n");
            }
        }else{
            printf("Congratulation, your answer %ld is correct!", receiveAnswer);
            break;
        }
    }
    printf("Your total score is %d/%d points.\n", score+receiveScore, n*8);
    return score+receiveScore;
}
int main(){
    unsigned n = 1, score = 0;
    long answer;
    printf("Answer questions with numbers in the range [1..100].\n"
    "You score points for each correctly answered question.\n"
    "If you need multiple attempts to answer a question, the\n"
    "points you score for a correct answer go down.\n");
    while(1){
        getText();
        answer = atoi(Answer);
        play(n++, score, question, answer);
    }
    return 0;
}


