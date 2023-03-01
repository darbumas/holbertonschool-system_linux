#include "httprotocol.h"
#include <string.h>

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
 * parse_request - prints full HTTP request with all queries key/value pairs.
 * @client_id: client socket descriptor
 * @buffer: buffer containing received message
 * Return: 0 on success, otherwise 1
 */
int parse_request(int client_id, char *buffer)
{
	char *query, *path, *saveptr1, *saveptr2, *delim = " \t\r\n";
	char *key, *val;

	strtok(buffer, delim);
	path = strtok(NULL, delim);
	path = strtok_r(path, "?", &saveptr1);
	printf("Path: %s\n", path);
	query = strtok_r(NULL, "&", saveptr1);

	while (query)
	{
		key = strtok_r(query, "=", &saveptr2);
		val = strtok_r(NULL, "=", &saveptr2);
		printf("Query: \"%s\" -> \"%s\"\n", key, val);
		query = strtok_r(NULL, "&", &saveptr1);
	}
	return (send_response(client_id, "HTTP/1.1 200 OK\n\n"));
}
