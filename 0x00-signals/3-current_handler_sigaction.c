#include "signals.h"

/**
 * current_handler_sigaction - retrieves the current handler of SIGINT
 *
 * Return: pointer to the current handler of SIGINT on success, or NULL
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction act;

	if (sigaction(SIGINT, NULL, &act) == -1)
		return (NULL);

	if (sigaction(SIGINT, &act, NULL) == -1)
		return (NULL);

	return (act.sa_handler);
}
