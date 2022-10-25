#include "hls.h"

/**
 * permissions - read the permissions in struct mode and format
 * @file: the struct that contains the info of a file
 * Return: a format permissions string
 */
char *permissions(struct stat file)
{
		char *options;
		mode_t perm = file.st_mode;

		options = malloc(sizeof(char) * 11);
		if (options == NULL)
			return (NULL);

		options[0] = ((perm & S_IFMT) == S_IFDIR) ? 'd' : '-';
		options[1] = (perm & S_IRUSR) ? 'r' : '-';
		options[2] = (perm & S_IWUSR) ? 'w' : '-';
		options[3] = (perm & S_IXUSR) ? 'x' : '-';
		options[4] = (perm & S_IRGRP) ? 'r' : '-';
		options[5] = (perm & S_IWGRP) ? 'w' : '-';
		options[6] = (perm & S_IXGRP) ? 'x' : '-';
		options[7] = (perm & S_IROTH) ? 'r' : '-';
		options[8] = (perm & S_IWOTH) ? 'w' : '-';
		options[9] = (perm & S_IXOTH) ? 'x' : '-';
		options[10] = '\0';
		return (options);
}
/**
 * get_date - obtain the date
 * @file: the struct that contains the info of a file
 * Return: a format string with date
 */
char *get_date(struct stat file)
{
	char *date = _strdup(ctime(&file.st_mtime));
	char buffer[48];


	sprintf(buffer, "%c%c%c %c%c %c%c:%c%c",
					date[4], date[5], date[6], date[8], date[9],
					date[11], date[12], date[14], date[15]);
	free(date);
	date = _strdup(buffer);
	return (date);
}
/**
 * parse_date - obtain the date
 * @file: the struct that contains the info of a file
 * Return: a format string with date
 */
long int parse_date(struct stat file)
{
	char *date = _strdup(ctime(&file.st_mtime));
	char buffer[48], m[4];
	char Epoch[5];
	char month[3];
	/* char *ptr; */


	Epoch[0] = date[20], Epoch[1] = date[21],
	Epoch[2] = date[22], Epoch[3] = date[23], Epoch[3] = '\0';
	sprintf(m, "%c%c%c", date[4], date[5], date[6]);
	!_strcmp(m, "Jan") ? month[0] = '0', month[1] = '1' : 1;
	!_strcmp(m, "Feb") ? month[0] = '0', month[1] = '2' : 1;
	!_strcmp(m, "Mar") ? month[0] = '0', month[1] = '3' : 1;
	!_strcmp(m, "Apr") ? month[0] = '0', month[1] = '4' : 1;
	!_strcmp(m, "May") ? month[0] = '0', month[1] = '5' : 1;
	!_strcmp(m, "Jun") ? month[0] = '0', month[1] = '6' : 1;
	!_strcmp(m, "Jul") ? month[0] = '0', month[1] = '7' : 1;
	!_strcmp(m, "Aug") ? month[0] = '0', month[1] = '8' : 1;
	!_strcmp(m, "Sep") ? month[0] = '0', month[1] = '9' : 1;
	!_strcmp(m, "Oct") ? month[0] = '1', month[1] = '0' : 1;
	!_strcmp(m, "Nov") ? month[0] = '1', month[1] = '1' : 1;
	!_strcmp(m, "Dec") ? month[0] = '1', month[1] = '2' : 1;
	month[2] = '\0';

	sprintf(buffer, "%s%s%c%c%c%c%c%c", Epoch, month, date[8], date[9],
	date[11], date[12], date[14], date[15]);

	free(date);
	return (_atoi(buffer));
}
