#include "httprotocol.h"

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
 * parse_request - parses the first line of the request
 * @client_id: client socket descriptor
 * @buffer: buffer containing received message
 * Return: 0 on success, otherwise 1
 */
int parse_request(int client_id, char *buffer)
{
	char *method, *path, *protocol, *delim = " \t\r\n";

	method = strtok(buffer, delim);
	path = strtok(NULL, delim);
	protocol = strtok(NULL, delim);
	printf("HTTP method: %s\nRequested path: %s\nProtocol version: %s\n",
			method, path, protocol);

	return (send_response(client_id, "HTTP/1.1 200 OK\n\n"));
}
