#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 64

int main() { 
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result,count;
    char ostr[BUFFER_SIZE],istr[BUFFER_SIZE];
    memset(istr, 0, sizeof(istr));
    memset(ostr, 0, sizeof(ostr));

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9129;
    len = sizeof(address);
    if((result = connect(sockfd,(struct sockaddr*)&address,len)) == -1) {
        printf("error\n");
        exit(1);
    }
    do {
        // Writing a message
        printf("\nYou: ");
        fgets(istr, BUFFER_SIZE, stdin);
        write(sockfd, istr, BUFFER_SIZE);
        count = read(sockfd, ostr, BUFFER_SIZE);
        printf("Server: ");
        printf("%s\n", ostr);
        if ((strncmp(istr, "bye", 3) == 0) && (strncmp(ostr, "bye", 3) == 0)) {
            break;
        }
    } while(1);

    close(sockfd);
    exit(0);
}
