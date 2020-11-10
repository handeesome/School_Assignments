#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <event2/event.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define SERVER_PORT 1234;


char* fortune(){
    int pfd[2]; //pipe
    pid_t p;
    char* argument_list[] = {"fortune", "-n", "32", "-s", NULL};
    int datasize = 50;
    char* data = (char*) malloc(sizeof(char)*datasize);
    int  stdout_bk; //stdout fd backup
    stdout_bk = dup(fileno(stdout));

    if (pipe(pfd)==-1){
            fprintf(stderr, "Pipe Failed" );
            exit(1);
    }
    p = fork();
    if (p < 0){
        fprintf(stderr, "fork Failed" );
        exit(1);
    }
    //parent process
    else if (p>0){
        close(pfd[1]);
        read(pfd[0], data, datasize);// read phrases created by fortune
        dup2(stdout_bk, fileno(stdout));//restore
        kill(p,SIGKILL);
        return data;
    }
    //child process
    else{
        close(pfd[0]);
        dup2(pfd[1], fileno(stdout));
        execvp("fortune", argument_list);
    }

}

static void accept(evutil_socket_t fd, short what, void* evb){
    char greet_msg[256] = "nc localhost 1234\n
                           M: Guess the missing ____!\n
                           M: Send your guess in the form \'R:word\\r\\n\'.\n";
    int client_socket;
    char buffer[200]; // stores incoming message
    int iDataNum; // takes record of how long is the incoming message

    //accpet client socket from server
    client_socket = accept(fd, (struct sockaddr*) &client_socket, (socklen_t *) &addr_len));
    if(client_socket < 0){
        perror("accept client failed!");
        continue;
    }

    //send greeting message
    send(client_socket, greet_msg, sizeof(greet_msg), 0);

    char *challenge;
    while(1){
        //get phrases from fortune
        challenge = fortune();
        //count how many phrases
        int count = 0;
        char *delim = " ";
        char *ptr = strtok(challenge, delim);
        char *phrases[10];// to store phrase pointers
        while (ptr!=NULL){
            phrases[count] = ptr;
            ptr = strtok(NULL, delim);
            count++;
        }
        int underscore_phrase = rand()%count;
        int answer_length = strlen(phrases[underscore_phrase]);
        char *answer = (char*) malloc(sizeof(char)*answer_length);
        strcpy(answer, phrases[underscore_phrase]); //backup answer
        for(int i=0; i<answer_length; i++)
            phrases[underscore_phrase][i] = '_';
        //create a challenge
        for(int i=1; i<count; i++){
            strcat(challenge, " ");
            strcat(challenge, phrases[i]);
        }
        //send challenge
        send(fd, challenge, strlen(challenge), 0);

        buffer[10];
        buffer[0] = '\0';
        iDataNum = recv(client_socket, buffer, 1024, 0);//receieve answer
        if(iDataNum < 0){
            perror("Nothing received!");
            continue;
        }
        buffer[iDataNum] = '\0';
        
        // disconnect a client
        if(strcmp(buffer, "quit") == 0) break;
    }
}

int main(){

    
    // create the server socket
    int server_socket;
    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("create server socket failed!");
        return 1;
    }
    // specify an address for server_socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons[SERVER_PORT];
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to specified IP and port
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        perror("bind socket with IP and port failed!");
        return 1;
    }
    if (listen(server_socket, 5) < 0){
        perror("listen failed!");
        return 1;
    }

    if (event_base *evb = event_base_new()<0){
        perror("create event base failed!");
        return 1;
    }

    while (1){
        event *ev = event_new(evb, server_socket, EV_READ | EV_PERSIST, accept, evb);
        event_add(ev, NULL);
    }
    
    close(server_socket);
    return 0;
}