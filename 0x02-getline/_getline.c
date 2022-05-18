#include "_getline.h"

char *read_buf(char *, int);
/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor to read from
 * Return: pointer to the text read.
 */

char *_getline(const int fd)
{
	static char *buf;
	char *line;
	static int file, size;

	if (fd != file || size >= READ_SIZE)
	{
		file = fd;
		buf = malloc(sizeof(char *) * READ_SIZE);
		read(fd, buf, READ_SIZE);
		size = 0;
		line = strdup(buf);
		line = read_buf(line, 1);
		if (line != NULL)
			size += strlen(line) + 1;
		if (buf[0] == '\000')
			return (NULL);
		return (line);
	}
	line = strdup(buf);
	line = read_buf(line, 0);
	if (line != NULL)
		size += strlen(line) + 1;
	return (line);
}

/**
 * readbuf - returns text read from buffer
 * @buf: pointer to buffer
 * @file: indicates if file is present
 * Return: text from buffer
 */

char *readbuf(char *buf, int file)
{
	char *txt;
	static int alpha, omega;
	int i = 0;

	if (file)
		omega = 0;
	alpha = omega;
	if (buf[omega] == '\000')
	{
		free(buf);
		return (NULL);
	}
	txt = malloc(sizeof(char *) * READ_SIZE);
	while (buf[omega] != '\n' && buf[omega] != '\000')
	{
		omega++;
		i++;
	}
	strncpy(txt, buf + alpha, i);
	omega++;
	alpha++;
	return (txt);
}
