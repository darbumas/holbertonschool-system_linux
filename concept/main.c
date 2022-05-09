#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	DIR *dir;
	char *dirp;
	struct dirent *read;

	if (argc <= 1)
		dirp = ".";
	else
		dirp = argv[1];

	dir = opendir(dirp);
	if (dir == NULL)
		printf("Error: directory not found");
	read = readdir(dir);
	while (read != NULL)
	{
		printf("%s\n", read->d_name);
		read = readdir(dir);
	}
	closedir(dir);
	return (1);
}
