#include "hls.h"
/**
 * main - program start
 * @argc: argument count
 * @argv: argument pointers
 *
 * Return: 1 upon success, -1 otherwise
 */

int main(int argc, char **argv)
{
	DIR *dir;
	char *dirPtr;
	int pos[60];
	int file;

	if (argc <= 1)
	{
		dirPtr = ".";
		dir = opendir(dirPtr);
		if (dir == NULL)
			return (0);
		_readdir(dir, dirPtr);
		closedir(dir);
	}
	else
	{
		readOption(pos, argv, argc);
		file = dirread(argc, argv, pos);
	}
	return (file);
}

/**
 * readOption - sets index of arguments.
 * @pos: array of index for found files
 * @argv: pointer to input argument
 * @argc: argument count
 *
 * Return: Nothing
 */
void readOption(int *pos, char **argv, int argc)
{
	int i;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
			pos[i] = 1;
		else
			pos[i] = 0;
	}
}
