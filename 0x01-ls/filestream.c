#include "hls.h"
/**
 * _readdir - reads directory and prints the files in it (if found).
 * @dir: pointer to the stream
 * @dir_name: points to the name of given directory
 *
 * Return: 1 on success
 */
int _readdir(DIR *dir, char *dir_name)
{
	char *buf, *err_buf;
	char *name = dir_name;
	struct stat filestat;
	struct dirent *read;
	int statResp;

	buf = malloc(256);
	if (buf == NULL)
		return (0);
	read = readdir(dir);
	while (read)
	{
		statResp = lstat(read->d_name, &filestat);
		if (dir_name[0] != '.')
		{
			sprintf(buf, "./%s/%s", dir_name, read->d_name);
			name = buf;
		}
		statResp = lstat(name, &filestat);

		if (statResp != 0)
		{
			err_buf = malloc(256);
			sprintf(err_buf, "./hls: cannot access %s", buf);
			perror(err_buf);
			free(buf);
			free(err_buf);
			return (0);
		}
		if (_strncmp(read->d_name, ".", 1) && _strncmp(read->d_name, "..", 2))
		{
			printf("%s", read->d_name);
			if (read != NULL)
				printf(" ");
		}
		read = readdir(dir);
	}
	printf("\n");
	free(buf);
	return (1);
	}

/**
 * dirread - opens and reads dir from argv
 * @argc: argument count
 * @argv: argument vector
 * @pos: position of the file
 * Return: 1 on success
 */
int dirread(int argc, char **argv, int *pos)
{
	DIR *dir;
	int file, err;
	char *err_buf, *dirPtr;

	for (file = 1; file < argc; file++)
	{
		if (pos[file] != 0)
		{
			dirPtr = argv[file];
			dir = opendir(dirPtr);
			err = errno;
			if (dir == NULL)
			{
				if (err == ENOTDIR)
					printf("%s\n", dirPtr);
				else
				{
					err_buf = malloc(256);
					sprintf(err_buf, "./hls: cannot access %s", dirPtr);
					perror(err_buf);
					free(err_buf);
				}
			}
			else
			{
				if (argc > 2)
					printf("%s:\n", dirPtr);
				_readdir(dir, dirPtr);
			}
			closedir(dir);
		}
		if (file + 1 < argc)
			printf("\n");
	}
	return (1);
}
