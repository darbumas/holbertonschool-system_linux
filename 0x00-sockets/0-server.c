#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 12345

/**
 * main - program opens an IP4/TCP socket, and listens to traffic
 * on port 12345
 * Return: SUCCESS or FAILURE
 */
int main(void)
{
	struct sockaddr_in addr;
	int sd;

	sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		perror("socket FAILED!");
		return (EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		perror("bind FAILED!");
		return (EXIT_FAILURE);
	}

	if (listen(sd, 10) == -1)
	{
		perror("listen FAILED");
		return (EXIT_FAILURE);
	}

	printf("Server up, listening on port 12345\n");
	while (1)
		;
	return (EXIT_SUCCESS);
}

