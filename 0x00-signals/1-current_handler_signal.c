#include "signals.h"

/**
 * current_handler_signal - retrieves the current handler of SIGINT
 *
 * Return: a pointer to the current handler function of the sig
 */
typedef void(*sighandler_t)(int);

void (*current_handler_signal(void))(int)
{
	sighandler_t func;

	func = signal(SIGINT, SIG_IGN);
	if (func == SIG_ERR)
		return (NULL);

	if (signal(SIGINT, func) == SIG_ERR)
		return (NULL);

	return (func);
}
