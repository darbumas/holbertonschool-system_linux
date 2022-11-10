#include "signals.h"

/**
 * main - prints a description of a given signal
 * @argc: cmd line args count
 * @argv: cmd line array of args
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	printf("%s: %s\n", argv[1], strsignal(atoi(argv[1])));

	return (EXIT_SUCCESS);
}

