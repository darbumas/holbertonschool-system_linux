#include "_getline.h"

FILE_T *append_file(int);
char *flash_buf(FILE_T *, FILE_T **, FILE_T **);
/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor to read from
 * Return: pointer to the text read.
 */

char *_getline(const int fd)
{
	static FILE_T *file;
	FILE_T *doc = file;
	char *string;
	int i, j;

	if (!file)
	{
		file = append_file(fd);
		doc = file;
	}
	else
	{
		while (doc)
		{
			if (doc->fd == fd)
				break;
			if (!doc->next)
				doc->next = append_file(fd);
			doc = doc->next;
		}
	}
	i = doc->one;
	j = doc->two;
	if (doc->buffer[i] == '\0' || fd == -1)
		return (flash_buf(file, &file, &doc));
	while (doc->buffer[i])
	{
		if (doc->buffer[i] == '\n' || doc->buffer[i + 1] == '\0')
		{
			string = malloc(sizeof(char *) * (i - j));
			strncpy(string, doc->buffer + j, i - j + 1);
			j = i + 1;
			doc->one = doc->two = j;
			return (string);
		}
		i++;
	}
	return (NULL);
}

/**
 * append_file - returns a pointer to a struct with a read file in buffer.
 * @fd: file descriptor
 * Return: pointer to a struct
 */
FILE_T *append_file(int fd)
{
	FILE_T *pointer;

	pointer = malloc(sizeof(FILE_T));
	pointer->fd = fd;
	pointer->buffer = malloc(sizeof(char *) * READ_SIZE);
	read(fd, pointer->buffer, READ_SIZE);
	pointer->one = 0;
	pointer->two = 0;
	return (pointer);
}

/**
 * flash_buf - frees up memory
 * @head: head node
 * @file: pointer to pointer to files
 * @doc: pointer to pointer to files
 * Return: NULL
 */
char *flash_buf(FILE_T *head, FILE_T **file, FILE_T **doc)
{
	FILE_T *next;

	while (head)
	{
		next = (*head).next;
		free((*head).buffer);
		free(head);
		if (next == NULL)
			head = NULL;
		else
			head = next;
	}
	free(head);
	free(next);
	*file = NULL;
	*doc = NULL;
	return (NULL);
}
