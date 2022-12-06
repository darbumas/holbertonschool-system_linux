#include "hls.h"
/**
 * option_l - manages the "l" option
 * Description: print in long format
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * @buffer: buffer
 * Return: Nothing
 */
void option_l(char **files, char *folder, char **buffer)
{
	struct stat file;
	int i;
	char buf[48];
	struct passwd *usr;
	struct group *grp;
	char *perm, *date;
	char buff[512];

	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buf, "%s/%s", folder, files[i]);

		if (lstat(buf, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		usr = getpwuid(file.st_uid);
		grp = getgrgid(file.st_gid);
		perm = permissions(file);
		date = get_date(file);
		sprintf(buff, "%s %ld %s %s %ld %s %s\n",
		perm,
		(long) file.st_nlink,
		usr->pw_name != NULL ? usr->pw_name : "",
		grp->gr_name != NULL ? grp->gr_name : "",
		(long) file.st_size,
		date,
		files[i]
		);
		free(files[i]);
		free(perm);
		free(date);
		_strcat(*(buffer), buff);
	}
	free(files);
}
/**
 * option_a - manages the "a" option
 * Description: print hidden folders
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * Return: array of folders
 */
char **option_a(char **files, char *folder)
{
	int i, j;
	char **buffer;
	(void) folder;

	buffer = _calloc(48, sizeof(*buffer));
	for (i = 0, j = 0; files[i] != NULL; i++)
	{
		if (files[i][0] != '.')
		{
			buffer[j] = _strdup(files[i]);
			j++;
		}


	free(files[i]);
	}
	free(files);
	return (buffer);
}
/**
 * option_A - manages the "A" options
 * Description: print hidden files with exceptions
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * section header: the header of this function is ls.h
 * Return: void
 */
char **option_A(char **files, char *folder)
{
	int i, j;
	char **buffer;
	(void) folder;

	buffer = _calloc(48, sizeof(*buffer));
	for (i = 0, j = 0; files[i] != NULL; i++)
	{
		if (_strcmp(files[i], ".") != 0 && _strcmp(files[i], "..") != 0)
		{
			buffer[j] = _strdup(files[i]);
			j++;
		}
	free(files[i]);
	}
	free(files);
	return (buffer);
}
/**
 * option_1 - manages the "1" option
 * Description: print each file on separate line
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * @buffer: the print buffer
 * Return: void
 */
void option_1(char **files, char *folder, char **buffer)
{
	int i;
	(void) folder;

	for (i = 0; files[i] != NULL; i++)
	{
		_strcat(*(buffer), files[i]);
		_strcat(*(buffer), "\n");
		free(files[i]);
	}
	free(files);
}
/**
 * no_option- function to manage the normal print
 * Description: normal ls print
 * @files: the files that the folder contains
 * @folder: the folder that is print
 * @buffer: the print buffer
 * Return: void
 */
void no_option(char **files, char *folder, char **buffer)
{
	int i;
	(void) folder;
	for (i = 0; files[i] != NULL; i++)
	{
		_strcat(*(buffer), files[i]);
		_strcat(*(buffer), "  ");
		free(files[i]);
	}
	free(files);
}
