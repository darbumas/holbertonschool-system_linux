#include "hls.h"
/**
 * add_node - adds a new node to a list
 * @head: the head of list
 * @str: the string to put in the new node
 * @file: info
 * Return: the head of the list.
 */
file_t *add_node(file_t **head, char *str, struct stat file)
{
	file_t *new;
	file_t *actual;

	actual = *head;
	new = malloc(sizeof(file_t));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->var = _strdup(str);
	new->time = parse_date(file);
	new->size = (long) file.st_size;
	if (actual == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (actual->next)
	{
		actual = actual->next;
	}
	actual->next = new;
	new->prev = actual;
	return (new);
}
/**
 * print_list - prints a list
 * @head: the head of list
 * Return: the number of nodes
 **/
size_t print_list(file_t **head)
{
	int i;

	file_t *h = *head;

	for (i = 0; h ; i++)
	{
		if (h->var == NULL)
			printf("[0] (nil)\n");
		else
			printf("file -> {%s} size -> {%li} -> {%lu}\n", h->var, h->size, h->time);
		h = h->next;
	}
	printf("\n");
	return (i);
}
/**
 * free_list - frees a linked list
 * @head: the head of list
 * Return: Nothing
 **/
void free_list(file_t **head)
{
	file_t *h;
	file_t *position, *next;


	h = *head;
	position = h;
	while (position != NULL)
	{
		next = position->next;
		free(position->var);
		free(position);
		position = next;
	}
	h = '\0';
}
/**
 * delete_node - deletes a node
 * @head: the head of list
 * @index: the index at which to delete node
 * Return: 1 on success; otherwise -1
 **/
int delete_node(file_t **head, unsigned int index)
{
	file_t *actual, *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	actual = *head;

	if (index == '\0')
	{
		*head = actual->next;
		free(actual);
		return (1);
	}

	for (i = 0; actual && i < index - 1; i++)
		actual = actual->next;

	if (actual == NULL || actual->next == NULL)
		return (-1);

	next = actual->next->next;
	free(actual->next->var);
	free(actual->next);
	actual->next = next;
	return (1);
}

/**
 * get_nodes - get the alloc blocks
 * @files: all the files in a folder
 * @folder: the folder thath containes the fail
 * Return: block size
 */
int get_nodes(char **files, char *folder)
{

	struct stat file;
	int i = 0;
	long int nodes = 0;
	char buffer[48];

	for (i = 0; files[i] != NULL; i++)
	{
		sprintf(buffer, "%s/%s", folder, files[i]);
		if (lstat(buffer, &file) == -1)
		{
			perror("lstat");
			exit(EXIT_FAILURE);
		}
		if (files[i][0] != '.')
			nodes += ((long) file.st_blocks / 2);
	}
	return (nodes);
}
