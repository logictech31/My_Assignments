#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#define BUFFER_SIZE 64

void *server_thread(void *arg) {
    int client_sockfd, istr_bye, ostr_bye;
    char istr[BUFFER_SIZE], ostr[BUFFER_SIZE];
    int count=0, exit = 0;

    memset(istr, 0, sizeof(istr));
    memset(ostr, 0, sizeof(ostr));
    client_sockfd = (int) arg;
    do {
        count = read(client_sockfd, istr, BUFFER_SIZE);
        // Server receives message
        printf("Client: %s\n", istr);
        // Server writes message
        istr_bye = strncmp(istr, "bye", 3);
        ostr_bye = strncmp(ostr, "bye", 3);
        if (istr_bye == 0 && ostr_bye == 0) {
            fprintf(stdout, "Closing Client!");
            break;
        }
        printf("You: ");
        fgets(ostr, BUFFER_SIZE, stdin);
        write(client_sockfd, ostr, BUFFER_SIZE);
    }while(1);
    close(client_sockfd);
    pthread_exit(NULL);
}

int main() {
    int server_sockfd,client_sockfd;
    int server_len,client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    pthread_t t;

    server_sockfd = socket(AF_INET,SOCK_STREAM,0);
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=9129;
    server_len=sizeof(server_address);

    if(bind(server_sockfd,(struct sockaddr*)&server_address,server_len)==-1) {
        printf("server error");
        exit(1);
    }
    printf("server waiting....\n");
    listen(server_sockfd,5);
    while(1) {
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
        printf("Connected to a client!\n");
        pthread_create(&t,NULL,server_thread,(void *) client_sockfd);
    }
    return 0;
}