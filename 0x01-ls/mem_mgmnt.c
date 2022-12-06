#include "hls.h"

/**
 * _calloc - allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory
 * @n: number of elements of the array
 * @size: number of bytes to be allocated
 * Return: address of new memory
 */
void *_calloc(unsigned int n, unsigned int size)
{
	void *ptr;

	if (n == 0 || size == 0)
		return (NULL);
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, (n * size));

	return (ptr);
}

/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 * with the constant byte c
 * @s: pointer to buffer
 * @c: constant byte to set in the buffer
 * @n: number of bytes to be altered
 * Return: pointer to the memory area s
 */
char *_memset(char *s, char c, unsigned int n)
{
	int i;

	for (i = 0; n > 0; i++, n--)
		s[i] = c;
	return (s);
}
