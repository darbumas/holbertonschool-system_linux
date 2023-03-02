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
#define BUFFER_SZ 8192

int server_start(void);
int roger_that(int);
int parse_request(int, char *);
int send_response(int, char *);

/**
 * struct post_s - Information needed for a HTTP POST request
 *
 * @id: id of current POST
 * @title: title of current POST
 * @desc: description of current POST
 * @next: next POST in the linked list.
 */
typedef struct post_s
{
	int id;
	char *title;
	char *desc;
	struct post_s *next;
} post_t;

#endif
