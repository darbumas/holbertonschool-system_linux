#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER 8192

/**
 * roger_that - accepts messages from a server socket
 * @sock_id: server socket file-descriptor
 * Return: SUCCESS or FAILURE.
 */
int roger_that(int sock_id)
{
	ssize_t read_sz;
	char buffer[BUFFER + 1];
	int client_id;
	struct sockaddr_in client;
	socklen_t client_sz = sizeof(client);

	client_id = accept(sock_id, (struct sockaddr *)&client, &client_sz);
	if (client_id == -1)
	{
		perror("accept FAILED");
		exit(1);
	}

	inet_ntop(AF_INET, &client.sin_addr, buffer, INET_ADDRSTRLEN);
	printf("Client connected: %s\n", buffer);

	read_sz = recv(client_id, buffer, BUFFER, 0);
	if (read_sz > 0)
	{
		buffer[read_sz] = 0;
		printf("Message received: \"%s\"\n", buffer);
	}
	close(client_id);
	return (EXIT_SUCCESS);
}

/**
 * main - program connects to a listening server;
 * prints a message if connection with server is successful.
 * Return: SUCCESS or FAILURE.
 */
int main(void)
{
	int sock_id;
	struct sockaddr_in server;

	sock_id = socket(PF_INET, SOCK_STREAM, 0);
	if (sock_id == -1)
	{
		perror("socket FAILED");
		exit(1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock_id, (struct sockaddr *)&server, sizeof(server)) == -1)
	{
		perror("bind FAILED");
		exit(1);
	}
	if (listen(sock_id, 10) == -1)
	{
		perror("listen FAILED");
		exit(1);
	}
	printf("Server listening on port %d\n", ntohs(server.sin_port));
	roger_that(sock_id);
	close(sock_id);
	return (EXIT_SUCCESS);
}
