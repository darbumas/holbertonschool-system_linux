#include "signals.h"

/**
 * SIGINT_printmsg - print message to stdout when signal is received
 * @signum: incoming signal
 */
void SIGINT_printmsg(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_sigaction - sets the handler for SIGINT
 *
 * Return: 0 on success, or -1
 */

int handle_sigaction(void)
{
	struct sigaction act;

	act.sa_handler = SIGINT_printmsg;

	return (sigaction(SIGINT, &act, NULL));
}
