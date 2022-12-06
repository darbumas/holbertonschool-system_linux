#include "hls.h"

/**
 * locate_folder - returns the correct folders
 * @argc: argument count
 * @argv: argument vector
 * @ret: return value; 0 for normal cases
 * @fcnt: folders count
 * @ficnt: files count
 * @err: count of errors
 * @args: pointer to args
 * Return: array of strings
 */
char **locate_folder(int argc, char **argv, int *ret, int *fcnt,
			int *err, int *ficnt, char *args)
{
	struct stat file;
	char **folders = NULL, **files;
	int i = 0, j = 0, d = 0, k = 0;

	files = _calloc(100, sizeof(*files));
	if (argc != 1)
	{
		folders = malloc(sizeof(*folders) * argc);
		if (folders == NULL)
			return (NULL);
		for (i = 1, j = 0; argv[i] != NULL; i++, j++)
		{
			if (lstat(argv[i], &file) == 0 && S_ISDIR(file.st_mode) &&
				!S_ISREG(file.st_mode))
				folders[j] = _strdup(argv[i]), (*fcnt)++;
			else if (argv[i][0] == '-')
				j--, _strcmp(argv[i], "--") != 0 ? d = 1 : 1;
			else if (lstat(argv[i], &file) == 0 && S_ISREG(file.st_mode))
				files[k] = _strdup(argv[i]), (*ficnt)++, j--, k++;
			else
				fprintf(stderr, "%s: cannot access %s: No such file or directory\n",
					argv[0], argv[i]), (*ret) = 2, (*err)++, j--;
		}
	}
	(*ficnt) > 0 ? print_dir(files, args, ".") : 1;
	(*ficnt) > 0 && (*fcnt) > 0 ? printf("\n") : 1;
	if (((*fcnt) == 0 && (*err) == 0 && (*ficnt) == 0) ||
		(d == 1 && ((*fcnt) == 0 && (*err) == 0 && (*ficnt) == 0)))
	{
		free(folders), folders = malloc(sizeof(*folders));
		if (folders == NULL)
			return (NULL);
		folders[0] = _strdup("."), (*fcnt)++;
	}
	if ((*ficnt) == 0)
		free(files);
	return (folders);
}

