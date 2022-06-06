#include "_getline.h"

char *returnline(FILE_T *head, const int fd);
char *copyline(FILE_T *buffer);
char *findchar(char *ptr, char c, ssize_t size);
void free_buf(FILE_T *head);
void *newmem(void *ptr, unsigned int prev, unsigned int new);

/**
 * _getline - reads entire line from stream
 * @fd: file descriptor
 *
 * Return: pointer to the characters read
 */
char *_getline(const int fd)
{
	char *line = NULL;
	static FILE_T head;

	if (fd == -1)
	{
		free_buf(&head);
		return (NULL);
	}
	line = returnline(&head, fd);
	if (line != NULL && line[0] == '\n' && !line[1])
		line[0] = 0;
	return (line);
}

/**
 * returnline - helper func for _getline
 * @head: head of the struct
 * @fd: file descriptor
 * Return: pointer to char (line)
 */

char *returnline(FILE_T *head, const int fd)
{
	FILE_T *fildes;

	if (head->buf == NULL && head->fd == 0 && head->next == NULL)
	{
		head->fd = fd;
		return (copyline(head));
	}
	while (head->next && head->next->fd <= fd)
		head = head->next;
	if (head->fd == fd)
		return (copyline(head));
	fildes = malloc(sizeof(*fildes));
	if (fildes == NULL)
		return (NULL);
	if (fd < head->fd)
	{
		memcpy(fildes, head, sizeof(*head)), memset(head, 0, sizeof(*head));
		head->fd = fd, head->next = fildes;
		return (copyline(head));
	}
	memset(fildes, 0, sizeof(*fildes));
	fildes->fd = fd, fildes->next = head->next, head->next = fildes;
	return (copyline(fildes));
}

/**
 * copyline - reads line from buffer
 * @buffer: buffer to read from
 *
 * Return: pointer to read line
 */
char *copyline(FILE_T *buffer)
{
	char buff[READ_SIZE + 1], *ptr, *line, *reg;
	ssize_t count = 0, size;

	size = buffer->len - buffer->i, reg = buffer->buf + buffer->i;
	ptr = findchar(reg, '\n', size);
	if (!buffer->len || buffer->i >= buffer->len || !ptr)
	{
		while (1)
		{
			count = read(buffer->fd, buff, READ_SIZE);
			if (count < 0 || (count == 0 && !buffer->len))
			{
				buffer->buf ? free(buffer->buf), buffer->buf = NULL : NULL;
				return (buffer->buf);
			}
			if (count == 0)
			{
				ptr = buffer->buf + buffer->len;
				break;
			}
			buffer->buf = newmem(buffer->buf, buffer->len, buffer->len + count + 1);
			if (buffer->buf == NULL)
				return (NULL);
			memcpy(buffer->buf + buffer->len, buff, count), buffer->len += count;
			reg = buffer->buf + (buffer->len - count);
			if (ptr != NULL)
			{
				buffer->buf[buffer->len] = 0;
				break;
			}
		}
	}
	*ptr = '\0', reg = buffer->buf + buffer->i;
	line = malloc(1 + (ptr - (reg)));
	if (line == NULL)
		return (NULL);
	memcpy(line, buffer->buf + buffer->i, 1 + (ptr - (reg)));
	buffer->i = (ptr - buffer->buf) + 1;
	if (buffer->i >= buffer->len)
		buffer->i = buffer->len = 0, free(buffer->buf), buffer->buf = NULL;
	return (line);
}

/**
 * findchar - finds a specific character and points to it.
 * @ptr: pointer
 * @c: character to find
 * @size: size
 * Return: pointer to char
 */
char *findchar(char *ptr, char c, ssize_t size)
{
	if (ptr == NULL)
		return (NULL);
	do {
		if (*ptr == c)
			return (ptr);
		ptr++;
	} while (--size > 0);
	return (NULL);
}

/**
 * free_buf - manages the EOF, and flush buffer
 * @head: buffer
 * Return: nothing
 */
void free_buf(FILE_T *head)
{
	FILE_T *fb = NULL, *temp;

	if (head->buf)
		free(head->buf), head->buf = NULL;
	for (fb = head->next; fb;)
	{
		if (fb->buf)
		{
			free(fb->buf);
			fb->buf = NULL;
		}
		temp = fb;
		fb = fb->next;
		free(temp);
	}
	memset(&head, 0, sizeof(head));
}

/**
 * newmem - changes memory block
 * @ptr: pointer to new memory block
 * @prev: size of previous block
 * @new: size of new block
 * Return: pointer
 */
void *newmem(void *ptr, unsigned int prev, unsigned int new)
{
	void *mem;

	if (new == prev)
		return (ptr);
	if (new == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		mem = malloc(new);
		if (mem == NULL)
		{
			free(ptr);
			return (NULL);
		}
		free(ptr);
		return (mem);
	}
	mem = malloc(new);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new > prev)
		memcpy(mem, ptr, prev);
	free(ptr);
	return (mem);
}
