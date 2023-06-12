#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "registration.h"

#include <rpc/rpc.h>

#define PORT 8080
#define MAXLINE 1024

int main()
{
    CLIENT *clnt;
    Student student;
    int *result;

    char *server = "localhost";  // Replace with the server's IP address if needed

    // Creating the RPC client
    clnt = clnt_create(server, REGISTRATION, REGISTRATION_V1, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror(server);
        exit(EXIT_FAILURE);
    }

    int reg_num;
    char name[50];

    printf("Enter registration number and name (e.g., 1234 John): ");
    scanf("%d %[^\n]", &reg_num, name);

    student.regNum = reg_num;
    student.name = name;

    result = register_1(&student, clnt);
    if (result == NULL) {
        clnt_perror(clnt, server);
        exit(EXIT_FAILURE);
    }

    if (*result == 1)
        printf("Registration successful.\n");
    else if (*result == -1)
        printf("Registration number already exists.\n");

    clnt_destroy(clnt);
    return 0;
}
