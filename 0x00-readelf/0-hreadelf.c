#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - displays info contained in ELF file header
 * @argc: argument count
 * @argv: arguments
 * @env: environment
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-h", "", NULL};

	(void) argc;
	args[3] = argv[1];
	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execve");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
