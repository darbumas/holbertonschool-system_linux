#include "multithreading.h"

/**
 * thread_entry - to serve as the entry point to a new thread
 * @arg: address of a string to print
 * Return: nothing
 */

void *thread_entry(void *arg)
{
	printf("%s\n", (char *)arg);
	pthread_exit(NULL);
}
