#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define SERVER_PORT 6666

/*
������һֱ����accept����״̬��
ֱ���пͻ������ӣ�
���ͻ�������quit�󣬶Ͽ���ͻ��˵�����
*/
int main() {

    //����socket�������ص��ļ�������

    int serverSocket;

    //���������׽���sockaddr_in�ṹ��������ֱ��ʾ�ͻ��˺ͷ�����

    struct sockaddr_in server_addr;

    struct sockaddr_in clientAddr;

    int addr_len = sizeof(clientAddr);

    int client;

    char buffer[200];

    int iDataNum;

    //socket������ʧ�ܷ���-1
    //int socket(int domain, int type, int protocol);
    //��һ��������ʾʹ�õĵ�ַ���ͣ�һ�㶼��ipv4��AF_INET
    //�ڶ���������ʾ�׽������ͣ�tcp���������ӵ��ȶ����ݴ���SOCK_STREAM
    //��������������Ϊ0
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));

    //��ʼ���������˵��׽��֣�����htons��htonl���˿ں͵�ַת�������ֽ���
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    //ip�����Ǳ���������ip��Ҳ�����ú�INADDR_ANY���棬����0.0.0.0���������е�ַ
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //����bind��accept֮��ĺ����������׽��ֲ���������Ҫǿ��ת����(struct sockaddr *)
    //bind�����������������˵��׽��ֵ��ļ���������

    if (bind(serverSocket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    //���÷������ϵ�socketΪ����״̬
    if (listen(serverSocket, 5) < 0) {
        perror("listen");
        return 1;

    }

    while (1) {

        printf("port: %d\n", SERVER_PORT);

        //����accept�����󣬻��������״̬
        //accept����һ���׽��ֵ��ļ��������������������˱��������׽��ֵ��ļ���������
        //serverSocket��client��
        //serverSocket��Ȼ�����ڼ���״̬��client������պͷ�������
        //clientAddr��һ������������accept����ʱ�������ͻ��˵ĵ�ַ�Ͷ˿ں�
        //addr_len��һ������-����������������ǵ������ṩ�Ļ�������clientAddr�ĳ��ȣ��Ա��⻺���������
        //�������ǿͻ��˵�ַ�ṹ���ʵ�ʳ��ȡ�
        //������-1
        client = accept(serverSocket, (struct sockaddr *) &clientAddr, (socklen_t *) &addr_len);

        if (client < 0) {
            perror("accept");
            continue;

        }

        printf("waiting for msg...\n");
        //inet_ntoa ip��ַת���������������ֽ���IPת��Ϊ���ʮ����IP
        //���ʽ��char *inet_ntoa (struct in_addr);
        printf("IP is %s\n", inet_ntoa(clientAddr.sin_addr));
        printf("Port is %d\n", htons(clientAddr.sin_port));

        while (1) {
            printf("reading msg:");
            buffer[0] = '\0';
            iDataNum = recv(client, buffer, 1024, 0);
            if (iDataNum < 0) {
                perror("recv null");
                continue;
            }

            buffer[iDataNum] = '\0';
            if (strcmp(buffer, "quit") == 0)
                break;
            printf("%s\n", buffer);
            printf("sending mag:");

            scanf("%s", buffer);
            printf("\n");
            send(client, buffer, strlen(buffer), 0);

            if (strcmp(buffer, "quit") == 0)
                break;
        }

    }

    close(serverSocket);
    return 0;
}
