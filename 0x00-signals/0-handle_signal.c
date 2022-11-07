#include "signals.h"

/**
 * print_gotcha - prints "Gotcha" to stdout when a signal (Control-C)
 * is sent
 * @sig: the signal number
 */
void print_gotcha(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_signal - 'SIGINT' signal handling function
 *
 * Return: 0 on success, or -1 on error
 */
int handle_signal(void)
{
	if (signal(SIGINT, print_gotcha) == SIG_ERR)
		return (-1);
	return (0);
}
