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
	struct dirent *read;
	struct stat filestat;
	int statResp;

	if (argc <= 1)
		dirPtr = ".";
	else
		dirPtr = argv[1];

	dir = opendir(dirPtr);
	if (dir == NULL)
		return (0);
	read = readdir(dir);
	while (read)
	{
		statResp = lstat(read->d_name, &filestat);
		if (statResp != 0)
			fprintf(stderr, "error in lstat: %s\n", strerror(errno));
		if (strncmp(read->d_name, ".", 1) && strncmp(read->d_name, "..", 2))
			printf("%s", read->d_name);
		read = readdir(dir);
		if (read != NULL)
			printf(" ");
	}
	printf("\n");
	closedir(dir);
	return (1);
}
