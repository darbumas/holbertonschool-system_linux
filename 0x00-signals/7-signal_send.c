#include "signals.h"

/**
 * main - sends the signal SIGINT to a given process PID
 * @argc: parameter count
 * @argv: array of parameters
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (kill((pid_t)atoi(argv[1]), SIGINT) != 0)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
