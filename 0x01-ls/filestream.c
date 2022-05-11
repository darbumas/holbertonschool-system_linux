#include "hls.h"
/**
 * _readdir - reads directory and prints the files in it (if found).
 * @dir: pointer to the stream
 * @dir_name: points to the name of given directory
 * @flags: flag passed for formatting
 * @flagCnt: number of flags passed
 *
 * Return: 1 on success
 */
int _readdir(DIR *dir, char *dir_name, char *flags, int flagCnt)
{
	char *buf;
	char *name = dir_name;
	struct stat filestat;
	struct dirent *read;
	int statResp, err;

	buf = malloc(256);
	if (buf == NULL)
		return (0);
	read = readdir(dir);
	while (read)
	{
		if (dir_name[0] != '.')
		{
			sprintf(buf, "./%s/%s", dir_name, read->d_name);
			name = buf;
		}
		statResp = lstat(name, &filestat);
		err = errno;
		if (statResp != 0)
		{
			error_handler(err, buf);
			free(buf);
			return (0);
		}
		lsFormat(read, flags, flagCnt, filestat);
		read = readdir(dir);
	}
	printf("\n");
	free(buf);
	return (1);
	}

/**
 * dirread - opens and reads dir from argv
 * @flags: points to options given
 * @param: array of pointer to files/directory
 * @flagCnt: number of options
 * @paramCnt: number of files/directory to list
 * Return: 1 on success
 */
int dirread(char *flags, char **param, int flagCnt, int paramCnt)
{
	DIR *dir;
	int file, err;
	char *dirPtr;

	for (file = 0; file < paramCnt; file++)
	{
		dirPtr = param[file];
		dir = opendir(dirPtr);
		err = errno;
		if (dir == NULL)
		{
			if (err == ENOTDIR)
				printf("%s\n", dirPtr);
			else
				error_handler(err, dirPtr);
			closedir(dir);
		}
		else
		{
			if (paramCnt > 1)
				printf("%s:\n", dirPtr);
			_readdir(dir, dirPtr, flags, flagCnt);
		}
		closedir(dir);
	}
	return (1);
}
