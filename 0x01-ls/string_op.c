#include "hls.h"

/**
 * _strstr - locates first occurence of a substring
 * @haystack: string to search into
 * @needle: substring to search for
 * Return: Pointer the beginning of the located string
 * otherwise NULL
 */
char *_strstr(char *haystack, char *needle)
{
	char *i, *j;

	while (*haystack != '\0')
	{
		i = haystack;
		j = needle;

		while (*j == *haystack && *j != '\0' && *haystack != '\0')
		{
			haystack++;
			j++;
		}
		if (*j == '\0')
			return (i);
		haystack = i + 1;
	}
	return (NULL);
}

/**
 * _strdup - duplicates a string
 * @s: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *s)
{
	int i, j;
	char *ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	ptr = malloc(i * sizeof(s) + 1);
	if (ptr == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		*(ptr + j) = *(s + j);
	*(ptr + j) = '\0';
	return (ptr);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @s0: pointer to first string
 * @s1: pointer to second string
 * Return: 0 if both strings are equal; if different, a neg/pos value
 */
int _strcmp(char *s0, char *s1)
{
	int i;

	for (i = 0; s0[i] != '\0' || s1[i] != '0'; i++)
	{
		if (s0[i] != s1[i])
			return (s0[i] - s1[i]);
	}
	return (0);
}

/**
 * _strcat - appends the src string to the dest string.
 * @dest: pointer to the dest string
 * @src: pointer to the src string
 * Return: pointer to the resulting string 'dest'
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	return (dest);
}
