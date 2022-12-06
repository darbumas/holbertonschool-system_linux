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

	while (*haystack != '\0')
	{
		char *i = haystack;
		char *j = needle;

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
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *p;
	int i, s;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	p = malloc(i * sizeof(*str) + 1);
	if (p == NULL)
		return (NULL);
	for (s = 0; s < i; s++)
		*(p + s) = *(str + s);
	*(p + s) = '\0';
	return (p);
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
 * @s1: pointer to first string
 * @s2: pointer to second string
 * Return: 0 if both strings are equal; if different, a neg/pos value
 */
int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] != '\0' || s2[j] != '\0'; j++)
	{
		if (s1[j] != s2[j])
		{
			return (s1[j] - s2[j]);
		}
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
