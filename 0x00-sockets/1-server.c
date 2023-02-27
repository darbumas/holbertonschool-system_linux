#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 12345

/**
 * main - programs opens an IP4/TCP socket, and listens to port 12345;
 * accepts entering connection
 * Return: SUCCESS or FAILURE
 */
int main(void)
{
	struct sockaddr_in server, client;
	int client_id, sock_id = socket(PF_INET, SOCK_STREAM, 0);
	socklen_t client_sz = sizeof(client);
	char buffer[INET_ADDRSTRLEN];

	if (sock_id == -1)
	{
		perror("socket FAILED");
		return (EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sock_id, (struct sockaddr *)&server, sizeof(server)) == -1)
	{
		perror("bind FAILED");
		return (EXIT_FAILURE);
	}
	if (listen(sock_id, 10) == -1)
	{
		perror("listen FAILED");
		return (EXIT_FAILURE);
	}

	printf("Server listening on port %d\n", ntohs(server.sin_port));
	client_id = accept(sock_id, (struct sockaddr *)&client, &client_sz);
	inet_ntop(AF_INET, &client.sin_addr, buffer, sizeof(buffer));
	printf("Client connected: %s\n", buffer);
	close(client_id);
	close(sock_id);
	return (EXIT_SUCCESS);
}
