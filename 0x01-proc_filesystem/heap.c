#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**              
 * main - creates a string in the heap and prints               
 * Return: if malloc failes
 */
int main(void)
{
	pid_t pid;
	char *s;
	unsigned long int i;

	s = strdup("Holberton");
	if (s == NULL)
	{
	  fprintf(stderr, "Malloc failed\n");
	  return (EXIT_FAILURE);
	}

	i = 0;
	pid = getpid();
	while (s)
	{
	  printf("[%lu]\t\"%s\" @ (%p)\tpid: %i\n", i, s, (void *)s, pid);
	  sleep(1);
	  i++;
	}
	free(s);
	return (EXIT_SUCCESS);
}
