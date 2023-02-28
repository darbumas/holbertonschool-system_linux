#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

/**
 * main - program connects to a listening server;
 * prints a message if connection with server is successful.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: SUCCESS or FAILURE.
 */
int main(int argc, char **argv)
{
	int sock_id;
	struct sockaddr_in server;
	struct hostent *host;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", *argv);
		exit(1);
	}

	sock_id = socket(PF_INET, SOCK_STREAM, 0);
	host = gethostbyname(argv[1]);

	if (sock_id == -1)
	{
		perror("socket FAILED");
		return (EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr),
			&server.sin_addr);
	server.sin_port = htons(atoi(argv[2]));

	if (connect(sock_id, (struct sockaddr *)&server, sizeof(server)) == -1)
	{
		perror("connect FAILED");
		return (EXIT_FAILURE);
	}

	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(sock_id);
	return (EXIT_SUCCESS);
}
