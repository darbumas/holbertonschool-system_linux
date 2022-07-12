#include "signals.h"

/**
 * current_handler_signal - retrieves the current handler of SIGINT
 *
 * Return: pointer to the current handler function of the signal
 */

typedef void (*sighandler_t)(int);

void (*current_handler_signal(void))(int)
{
	sighandler_t h;

	h = signal(SIGINT, SIG_IGN);
	if (h == SIG_ERR)
		return (NULL);

	if (signal(SIGINT, h) == SIG_ERR)
		return (NULL);

	return (h);
}
