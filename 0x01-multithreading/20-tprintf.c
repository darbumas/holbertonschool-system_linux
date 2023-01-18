#include "multithreading.h"

static pthread_mutex_t mutex;

void mutex_init(void) __attribute__((constructor));
void mutex_destroy(void) __attribute__((destructor));

/**
 * mutex_init - initializes a mutex
 */
void mutex_init(void)
{
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		printf("pthread_mutex_init Failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * mutex_destroy - destroys a mutex
 */
void mutex_destroy(void)
{
	if (pthread_mutex_destroy(&mutex) != 0)
	{
		printf("pthread_mutex_destroy Failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * tprintf - prints a formatted string using a mutex to avoid race conditions.
 * @format: the given string to print
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	va_list ap;

	va_start(ap, format);

	if (pthread_mutex_lock(&mutex) != 0)
	{
		printf("pthread_mutex_lock Failed\n");
		exit(EXIT_FAILURE);
	}
	printf("[%lu] ", pthread_self());
	vprintf(format, ap);

	pthread_mutex_unlock(&mutex);

	va_end(ap);
	return (EXIT_SUCCESS);
}
