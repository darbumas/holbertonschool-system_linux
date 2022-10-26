#include "hls.h"

/**
 * confirm - evaluates to true or false whether options are valid
 * @str: pointer to the string to check
 * @opt: option to check
 * Return: True if option is valid, otherwise false
 */
bool confirm(char *str, char opt)
{
	int i;

	for (i = 0; i < _strlen(str); i++)
	{
		if (str[i] == opt)
			return (true);
	}
	return (false);
}
