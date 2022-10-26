#include "hls.h"

/**
 * _atoi - converts a string to integer
 *@str: the string for convert to integer
* Return: converted value.
*/
unsigned long int _atoi(char *str)
{
	unsigned long int i = 0;
	unsigned long int j = 0;

	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j);
}
