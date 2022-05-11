#include "hls.h"

/**
 * _strncmp - compares two strings
 * @str0: points to the first string
 * @str1: points to the second string
 * @n: most bytes in str0 & str1 to compare
 *
 * Return: 0 if same
 */

int _strncmp(char *str0, char *str1, int n)
{
	int i;
	int flag = 0;

	for (i = 0; i < n; i++)
	{
		if (str0[i] != str1[i])
		{
			flag = i + 1;
			break;
		}
	}
	return (flag);
}

/**
 * lsFormat - formats the way ls prints
 * @read: file metadata
 * @flags: points to the flags passed
 * @flagCnt: number of flags
 * @statbuf: points to the file in buffer.
 */
void lsFormat(struct dirent *read, char *flags, int flagCnt, struct stat statbuf)
{
	int i, j, k;

	j = 0;
	k = 0;

	statbuf = statbuf;
	if (flags != NULL)
	{
		for (i = 0; i < flagCnt; i++)
		{
			if (flags[i] == '1')
				j = 1;
			if (flags[i] == 'a')
				k = 1;
		}
	}
	if (k)
	{
		printf("%s", read->d_name);
		if (j)
			printf("\n");
		else
			printf(" ");
	}
	else if (_strncmp(read->d_name, ".", 1) && _strncmp(read->d_name, "..", 2))
	{
		printf("%s", read->d_name);
		if (j)
			printf("\n");
		else
			printf(" ");
	}
}
