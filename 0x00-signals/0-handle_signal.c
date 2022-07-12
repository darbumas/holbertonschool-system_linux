#include "signals.h"

/**
 * SIGINT_printmsg - prints a message to stdout when a signal is set
 * @signum: the incoming signal number
 *
 */
void SIGINT_printmsg(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_signal - handles the signal for SIGINT
 *
 * Return: 0 on success or -1
 */
int handle_signal(void)
{
	if (signal(SIGINT, SIGINT_printmsg) == SIG_ERR)
		return (-1);
	return (0);
}
