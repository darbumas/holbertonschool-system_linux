#include <errno.h>
#include <unistd.h>
#include "signals.h"

/**
 * SIGINT_printmsg - prints a message when SIGINT is received
 * @signum: signal
 *
 */
void SIGINT_printmsg(int signum)
{
	printf("Caught %d\n", signum);

	if (sigaction(SIGINT, NULL, NULL) != 0)
		return;
}

/**
 * main - sets a handler for signal SIGINT
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(void)
{
	struct sigaction act;

	act.sa_handler = SIGINT_printmsg;
	if (sigaction(SIGINT, &act, NULL) != 0)
		return (EXIT_FAILURE);
	pause();
	if (errno == EINTR)
		printf("Signal received\n");

	return (EXIT_SUCCESS);
}
