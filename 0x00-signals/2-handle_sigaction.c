#include "signals.h"

/**
 * print_gotcha - prints "Gotcha" to stdout when a signal is set
 *
 * @sig: the signal number
 */
void print_gotcha(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_sigaction - sets a handler for the SIGINT signal
 *
 * Return: 0 on success, or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction sig;

	sig.sa_handler = print_gotcha;

	return (sigaction(SIGINT, &sig, NULL));
}
