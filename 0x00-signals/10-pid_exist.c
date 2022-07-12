#include <signal.h>
#include <sys/types.h>

/**
 * pid_exist - tests if a process exist via given PID
 * @pid: process ID
 *
 * Return: 1 if process exist, or 0 if does NOT
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
