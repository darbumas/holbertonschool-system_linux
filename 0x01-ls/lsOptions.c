#include "hls.h"
/**
 * filecount - returns count of files in argv
 * @f_array: array of pointers to files in directory
 * @argv: argument vector
 * @argc: argument count
 * Return: count of directories/files to list
 */
int filecount(char **f_array, char **argv, int argc)
{
	int i;
	int count = 0;

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] != '-')
		{
			f_array[count] = argv[i];
			count++;
		}
	}
	if (count == 0)
	{
		f_array[0] = ".";
		count++;
	}
	return (count);
}

/**
 * flagcount - checks flags in argv and saves it.
 * @flags: points to the array of flags in argv
 * @argc: argument count
 * @argv: argument vector
 * Return: count of flags passed
 */
int flagcount(char *flags, int argc, char **argv)
{
	int i, k, count;

	count = 0;
	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (k = 1; argv[i][k] != '\0'; k++)
			{
				flags[count] = argv[i][k];
				count++;
			}
		}
	}
	return (count);
}
