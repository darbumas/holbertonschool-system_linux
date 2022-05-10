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
	//struct dirent *read;
	//struct stat filestat;
	//int statResp;
	int pos[argc];
	int file;

	if (argc <= 1)
	{
		dirPtr = ".";
		dir = opendir(dirPtr);
		if (dir == NULL)
			return (0);
		_readdir(dir, dirPtr);
	}
	else
		readOption(pos, argv, argc);

	for (file = 1; file < argc; file++)
	{
		if (pos[file] != 0)
		{
			dirPtr = argv[file];
			dir = opendir(dirPtr);
			if (dir == NULL)
			{
				fprintf(stderr, "./hls: cannot access %s: %s\n",
						dirPtr, strerror(errno));
			}
			else
			{
				printf("%s:\n", dirPtr);
				_readdir(dir, dirPtr);
			}
		}
		if (file + 1 < argc)
			printf("\n");
	}
	closedir(dir);
	return (1);
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
