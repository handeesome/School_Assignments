#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define SERVER_PORT 1234;

int main(){

    //create a client socket
    int client_socket;
    if((client_socket=socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("create client socket failed!");
    }

    //specify an address for the server socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons[SERVER_PORT];
    server_address.sin_addr.s_addr = INADDR_ANY;

    //connect client socket to the server
    if(connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0){
        printf("There is an error making a connection with the server!\n");
        perror("connect failed!");
        return 1;
    }
    
    char server_msg[256];
    char client_msg[256];
    recv(client_socket, &server_msg, sizeof(server_msg), 0);
    printf("%s\n", server_msg);
    while(1){
        //receive data from the server
        recv(client_socket, &server_msg, sizeof(server_msg), 0);
        printf("%s\n", server_msg);

        //send guess word to the server
        printf("R: ");
        scanf("%s", client_msg);
        send(client_socket, client_msg, strlen(client_msg), 0);
        if(strcmp(client_msg, "quit")==0) break;
    }

    close(client_socket);
    return 0;
}