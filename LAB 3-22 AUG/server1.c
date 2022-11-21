#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main()
{
    int sockfd;                           // Socket Number
    char buffer[MAXLINE];                 // Message from client
    char *hello = "Hello from Server";    // message from Server
    struct sockaddr_in servaddr, cliaddr; // IP addresses of Client and Server

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    { // Socket File Descriptor
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Client: %s\n", buffer);
    sendto(sockfd, hello, strlen(hello), 0, (const struct sockaddr *)&cliaddr, len);
    printf("Hello message sent.\n");
    return 0;
}