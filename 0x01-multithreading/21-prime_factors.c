#include "multithreading.h"

/**
 * prime_factors - factorizes a number into a list of prime factors.
 * @s: string representation of number to factorize
 * Return: list of prime factors; otherwise NULL
 */
list_t *prime_factors(char const *s)
{
	unsigned long *prime = NULL, num, i;
	list_t *list = NULL;

	if (!s)
		return (NULL);

	num = strtoul(s, NULL, 10);

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);

	list = list_init(list);

	for (i = 2; (i * i) <= num; i += (i == 2) ? 1 : 2)
	{
		while (num % i == 0)
		{
			prime = calloc(1, sizeof(unsigned long));
			*prime = i;
			list_add(list, prime);
			num /= i;
		}
	}
	if (num != 1)
	{
		prime = calloc(1, sizeof(unsigned long));
		*prime = num;
		list_add(list, prime);
	}
	return (list);
}
