#ifndef HTTPROTOCOL_H
#define HTTPROTOCOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>

#define CRLF "\r\n"
#define PORT 8080
#define BUFFER_SZ 1024

int server_start(void);
int roger_that(int);
int parse_request(int, char *);
int send_response(int, char *);

#endif
