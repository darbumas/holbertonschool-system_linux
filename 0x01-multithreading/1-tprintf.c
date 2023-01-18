#include "multithreading.h"

/**
 * tprintf - prints a formatted string preceded by the calling thread ID
 * @format: the given formatted string to print
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (EXIT_SUCCESS);
}
