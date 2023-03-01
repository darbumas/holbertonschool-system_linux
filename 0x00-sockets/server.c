#include "httprotocol.h"

#define MAX_CLIENTS 8

/**
 * server_start - creates a TCP socket, binds it to any address
 * on port 8080, and accepts messages.
 * Return: SUCCESS or FAILURE
 */
int server_start(void)
{
	int server_id;
	struct sockaddr_in address;

	/* Create a TCP socket, set buffer */
	setbuf(stdout, NULL);
	server_id = socket(PF_INET, SOCK_STREAM, 0);
	if (server_id < 0)
	{
		perror("socket FAILED");
		exit(EXIT_FAILURE);
	}

	/* Bind the socket to any address on port 8080 */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	if (bind(server_id, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind FAILED");
		exit(EXIT_FAILURE);
	}

	/* Start listening for incoming connections */
	if (listen(server_id, MAX_CLIENTS) < 0)
	{
		perror("listen FAILED");
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port %d\n", ntohs(address.sin_port));
	while (1)
		roger_that(server_id);
	close(server_id);
}

/**
 * roger_that - accepts messages from a server socket
 * @server_id: server socket file-descriptor
 * Return: SUCCESS or FAILURE.
 */
int roger_that(int server_id)
{
	ssize_t bytes_recv;
	char buffer[BUFFER_SZ + 1];
	int new_socket;
	struct sockaddr_in address;
	socklen_t addrlen = sizeof(address);

	new_socket = accept(server_id, (struct sockaddr *)&address, &addrlen);
	if (new_socket < 0)
	{
		perror("accept FAILED");
		exit(1);
	}

	inet_ntop(AF_INET, &address.sin_addr, buffer, INET_ADDRSTRLEN);
	printf("Client connected: %s\n", inet_ntoa(address.sin_addr));

	bytes_recv = recv(new_socket, buffer, BUFFER_SZ, 0);
	if (bytes_recv > 0)
	{
		buffer[bytes_recv] = 0;
		printf("Raw request: \"%s\"\n", buffer);
		parse_request(new_socket, buffer);
	}
	close(new_socket);
	return (EXIT_SUCCESS);
}

/**
 * send_response - sends an HTTP response back to the client
 * @client_id: client socket descriptor
 * @response: the message
 * Return: 0 on success, otherwise 1
 */
int send_response(int client_id, char *response)
{
	send(client_id, response, strlen(response), 0);
	return (0);
}
