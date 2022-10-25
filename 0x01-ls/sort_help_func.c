#include "hls.h"
/**
 * create_list - creates a double linked list to be manipulated
 * @files: double pointer to convert
 * @folder: pointer to convert
 * Return: pointer to the struct.
 **/
file_t *create_list(char **files, char *folder)
{
	int i;
	file_t *file_st;
	struct stat file;
	char buffer[48];

	file_st = NULL;
	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buffer, "%s/%s", folder, files[i]);
		if (lstat(buffer, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		add_node(&file_st, files[i], file);
		free(files[i]);
	}
	free(files);
	return (file_st);

}
/**
 * create_array - converts a list to a double pointer
 * @head: the head of list
 * Return: the double pointer.
 **/
char **create_array(file_t **head)
{
	int i;
	file_t *h = *head;
	char **files;

	for (i = 0; h; i++)
		h = h->next;
	files = _calloc(i + 1, sizeof(char *));
	h = *head;
	for (i = 0; h; i++, h = h->next)
		files[i] = _strdup(h->var);
	return (files);
}
/**
 * _atoi - converts a string to integer
 *@s: the string for convert to integer
* Return: converted value.
*/
unsigned long int _atoi(char *s)
{
	unsigned long int counter = 0;
	unsigned long int number = 0;

	while ((s[counter] >= '0') && (s[counter] <= '9'))
	{
		number = number * 10 + (s[counter] - '0');
		counter++;
	}
	return (number);
}
/**
 * _index - read the argv and select the valid args
 * @valid: this argument contains the number of args passed in the call
 * @arg: double pointer to the arguments passed in the call
 * Return: true if the arg is valid, otherwise false
 */
int _index(char *valid, char arg)
{
	int i;

	for (i = 0; i < _strlen(valid); i++)
	{
		if (valid[i] == arg)
			return (i);
	}
	return (-1);
}
/**
 * select_sort - read the argv and select the valid args
 * @args: double pointer to the arguments passed in the call
 * Return: true if the arg is valid, otherwise false
 */
char select_sort(char *args)
{
	if (confirm(args, 't'))
	{
		if (confirm(args, 'S'))
		{
			if (_index(args, 'S') > _index(args, 't'))
				;
			else
				return ('t');
		}
		else
			return ('t');
	}
	if (confirm(args, 'S'))
	{
		if (confirm(args, 't'))
		{
			if (_index(args, 't') > _index(args, 'S'))
				;
			else
				return ('S');
		}
		else
			return ('S');
	}
	return ('\0');
}
