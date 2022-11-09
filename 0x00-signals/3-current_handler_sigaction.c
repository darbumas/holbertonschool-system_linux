#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler
 * of the SIGINT signal
 *
 * Return: pointer to the current hnadler of SIGINT, or NULL
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction action;

	if (sigaction(SIGINT, NULL, &action) == -1)
		return (NULL);
	if (sigaction(SIGINT, &action, NULL) == -1)
		return (NULL);

	return (action.sa_handler);
}
