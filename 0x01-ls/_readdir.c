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
	char *restrict buf = malloc(256);
	char *name = dir_name;
	struct stat filestat;
	struct dirent *read;
	int statResp;

	read = readdir(dir);
	while (read)
	{
		statResp = lstat(read->d_name, &filestat);
		if (dir_name[0] != '.')
		{
			sprintf(buf, "./%s%s", dir_name, read->d_name);
			name = buf;
		}
		statResp = lstat(name, &filestat);

		if (statResp != 0)
		{
			fprintf(stderr, "./hls: cannot access %s: %s\n", name, strerror(errno));
			free(buf);
			exit(0);
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

