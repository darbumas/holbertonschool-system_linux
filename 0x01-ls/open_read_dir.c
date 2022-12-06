#include "hls.h"

/**
 * open_dir - opens a directory
 * @folder: folder to open
 * Return: pointer to the directory
 */
DIR *open_dir(char *folder)
{
	DIR *dir;

	dir = opendir(folder);
	if (dir)
		return (dir);
	else
		return (NULL);
}

/**
 * read_dir - reads a folder
 * @dir: directory to ready
 * @folder: name of folder
 * @ret: return values
 * @err: array of string for errors
 * Return: names of files in an array of strings.
 */
char **read_dir(DIR *dir, char *folder, int *ret, char **err)
{
	struct stat file;
	struct dirent *read;
	char **files = NULL;
	int i;

	if (lstat(folder, &file) == 0 && file.st_mode & S_IRUSR)
	{
		files = _calloc(100, sizeof(*files));
		for (i = 0; (read = readdir(dir)) != NULL; i++)
			files[i] = _strdup(read->d_name);
	}
	else
	{
		for (i = 0; *(err + i); i++)
		{
		}
		*(err + i) = _strdup(folder);
		*(ret) = 3;
	}
	if (files)
		files = sort(files, 1, folder);
	return (files);
}

/**
 * print_dir - prints content of folder
 * @files: files the folder contains
 * @args: args passed to ls to format the output
 * @folder: folder content of which tto print
 * Return: 0 upon success.
 */
int print_dir(char **files, char *args, char *folder)
{
	char *buffer;
	char s_mod;

	buffer = _calloc(8192, sizeof(char));
	s_mod = select_sort(args);
	if (s_mod == 't')
		files = sort(files, 3, folder);
	if (s_mod == 'S')
		files = sort(files, 4, folder);
	if (confirm(args, 'r'))
		files = sort(files, 2, folder);
	if (!confirm(args, 'a') && !confirm(args, 'A'))
		files = option_a(files, folder);
	if (confirm(args, 'A') && !confirm(args, 'a'))
		files = option_A(files, folder);
	if (confirm(args, '1') && !confirm(args, 'l'))
		option_1(files, folder, &buffer);
	if (confirm(args, 'l'))
		option_l(files, folder, &buffer);
	if (_strcmp(args, "-") == 0)
		no_option(files, folder, &buffer);
	else if (confirm(args, 'a') || confirm(args, 'A') || confirm(args, 'r')
			|| confirm(args, 'S') || confirm(args, 't'))
	{
		if (confirm(args, 'l') || confirm(args, '1'))
			;
		else
			no_option(files, folder, &buffer);
	}
	if (_strlen(buffer) > 0)
		printf("%s", buffer);
	if (!confirm(args, '1') && !confirm(args, 'l') && _strlen(buffer) > 0)
		printf("\n");
	free(buffer);
	return (0);
}
