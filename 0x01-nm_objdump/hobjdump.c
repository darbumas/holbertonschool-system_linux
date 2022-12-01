#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - program entry
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: 1, or 0
 */
int main(int argc, char **argv, char **env)
{
	char *cmd[] = {"./hobjdump", "-sf", "", NULL};

	(void)argc;

	cmd[2] = argv[1];
	if (execve("/usr/bin/objdump", cmd, env) == -1)
	{
		perror("execve");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
