#include "signals.h"

/**
 * SIGQUIT_handler - helps capture info of an incoming SIQUIT
 * @signum: incoming signal number
 * @info: pointer to struct containing signal info
 * @unused: third parameter to sa_sigaction
 */
void SIGQUIT_handler(int signum, siginfo_t *info, void *unused)
{
	(void)unused;

	if (signum == SIGQUIT)
		printf("SIGQUIT sent by %d\n", info->si_pid);
}

/**
 * trace_signal_sender - defines a handler for SIGQUIT
 *
 * Return: 0 on success, or -1
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	act.sa_sigaction = SIGQUIT_handler;

	return (sigaction(SIGQUIT, &act, NULL));
}
