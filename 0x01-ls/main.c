#include "hls.h"

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 upon success; or corresponding error codes
 */
int main(int argc, char *argv[])
{
	DIR *dir = NULL;
	char **dirs = NULL, **files = NULL, **err = NULL, *args = NULL;
	int i = 0, ret = 0, fcnt = 0, ecnt = 0, ficnt = 0;

	err = _calloc(12, sizeof(*err));
	if (err == NULL)
		return (-1);
	args = validate_args(argv, err);
	if (confirm(args, 'R'))
		dirs = locate_folder(argc, argv, &ret, &fcnt, &ecnt, &ficnt, args);
	else
		dirs = validate_dir(argc, argv, &ret, &fcnt, &ecnt, &ficnt, args);
	for (i = 0; i < fcnt; i++)
	{
		dir = open_dir(dirs[i]);
		files = read_dir(dir, dirs[i], &ret, &*err);
		if (files)
		{
			if (fcnt + ficnt + ecnt > 1)
				printf("%s:\n", dirs[i]);
			print_dir(files, args, dirs[i]);
			if (fcnt > 1 && i + 1 != fcnt)
				printf("\n");
		}
		closedir(dir);
		free(dirs[i]);
	}
	free(dirs);
	if (ret == 3)
	{
		for (i = 0; err[i] != NULL; i++)
			fprintf(stderr, "hls: cannot open directory %s: Permission denied\n", err[i]),
				free(err[i]);
		free(err), ret = 2;
	}
	else
		free(err);
	free(args);
	return (ret);
}
