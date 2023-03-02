#include "httprotocol.h"
#include <ctype.h>

/**
 * main - program entry
 *
 * Return: SUCCESS or FAILURE
 */
int main(void)
{
	return (server_start());
}

/**
 * trimwhitespace - trims whitespaces.
 * @ogstring: pointer to the original string.
 * Return: pointer to a substring without the whitespaces, or NULL.
 */
char *trimwhitespace(char *ogstring)
{
	ssize_t i;

	if (!ogstring)
		return (NULL);

	while (isspace((unsigned char)*ogstring))
		ogstring++;
	for (i = strlen(ogstring) - 1; i >= 0; i--)
	{
		if (!isspace((unsigned char)ogstring[i]))
			break;
		ogstring[i] = 0;
	}
	return (ogstring);
}

/**
 * parse_request - parses HTTP headers and prints fields.
 * @client_id: client socket descriptor
 * @buffer: buffer containing received message
 * Return: 0 on success, otherwise 1
 */
int parse_request(int client_id, char *buffer)
{
	char *saveptr1, *saveptr2;
	char *delim = "\r\n";
	char *header, *key, *val;

	strtok_r(buffer, delim, &saveptr1);
	header = strtok_r(NULL, delim, &saveptr1);

	while (header)
	{
		key = trimwhitespace(strtok_r(header, ":", &saveptr2));
		val = trimwhitespace(strtok_r(NULL, delim, &saveptr2));
		printf("Header: \"%s\" -> \"%s\"\n", key, val);
		header = strtok_r(NULL, delim, &saveptr1);
	}
	send_response(client_id, "HTTP/1.1 200 OK\n\n");
	return (0);
}
