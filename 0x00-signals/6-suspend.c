#include "signals.h"

/**
 * print_caught - prints a message when SIGINT is received
 * @signum: signal
 *
 */
void print_caught(int signum)
{
	printf("Caught %d\n", signum);

	if (sigaction(SIGINT, NULL, NULL) != 0)
		return;
}

/**
 * main - sets a handler for signal SIGINT and exists
 * immediately after the signal is handled
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(void)
{
	struct sigaction act;

	act.sa_handler = print_caught;
	if (sigaction(SIGINT, &act, NULL) != 0)
		return (EXIT_FAILURE);
	pause();
	if (errno == EINTR)
		printf("Signal received\n");

	return (EXIT_SUCCESS);
}

