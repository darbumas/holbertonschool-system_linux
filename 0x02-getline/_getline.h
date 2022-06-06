#ifndef _GETLINE_H
#define _GETLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_SIZE 1024

/**
 * struct fildes - defines a struct for a file descriptor
 * @fd: file descriptor
 * @i: index
 * @len: length of buf
 * @buf: buffer to read from
 * @next: points to the next node
 */
typedef struct fildes
{
	int fd;
	char *buf;
	size_t i;
	size_t len;
	struct fildes *next;
} FILE_T;

char *_getline(const int);

#endif
