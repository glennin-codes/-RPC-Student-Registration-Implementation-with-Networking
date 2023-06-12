#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <rpc/rpc.h>

#include "registration.h"

#define PORT 8080
#define MAXLINE 1024

int *register_1_svc(Student *student, struct svc_req *rqstp) {
    static int result = 0;
    FILE *fp;
    char fileBuf[MAXLINE];

    char regNumStr[20];
    sprintf(regNumStr, "%d", student->regNum);

    char *regNum = regNumStr;
    char *name = student->name;

    if ((fp = fopen("students.txt", "r")) == NULL) {
        fp = fopen("students.txt", "w");
        fprintf(fp, "%s %s\n", regNum, name);
        fclose(fp);
        result = 1;
        return &result;
    }

    while (fgets(fileBuf, MAXLINE, fp) != NULL) {
        if (strstr(fileBuf, regNum) != NULL) {
            printf("Registration number already exists.\n");
            fclose(fp);
            result = -1;
            return &result;
        }
    }

    fclose(fp);
    fp = fopen("students.txt", "a");
    fprintf(fp, "%s %s\n", regNum, name);
    fclose(fp);
    result = 1;
    return &result;
}

// int main() {
//     int sockfd;
//     struct sockaddr_in servaddr, cliaddr;

//     // Creating socket file descriptor
//     sockfd = socket(AF_INET, SOCK_DGRAM, 0);
//     if (sockfd < 0) {
//         perror("socket creation failed");
//         exit(EXIT_FAILURE);
//     }

//     memset(&servaddr, 0, sizeof(servaddr));
//     memset(&cliaddr, 0, sizeof(cliaddr));

//     // Filling server information
//     servaddr.sin_family = AF_INET;
//     servaddr.sin_addr.s_addr = INADDR_ANY;
//     servaddr.sin_port = htons(PORT);

//     // Bind the socket with the server address
//     if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
//         perror("bind failed");
//         exit(EXIT_FAILURE);
//     }

//     svc_run();
//     return 0;
// }
