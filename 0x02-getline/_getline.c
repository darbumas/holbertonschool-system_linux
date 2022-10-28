#include "_getline.h"

/**
 * _getline - reads entire line from stream
 * @fd: file descriptor
 *
 * Return: pointer to the lines read
 */
char *_getline(const int fd)
{
	FILE_T *fb = NULL, *tmp;
	char *line = NULL;
	static FILE_T head;

	if (fd == -1)
	{
		if (head.buf)
			head.buf = (free(head.buf), NULL);
		for (fb = head.next; fb;)
		{
			if (fb->buf)
			{
				free(fb->buf);
				fb->buf = NULL;
			}
			tmp = fb;
			fb = fb->next;
			free(tmp);
		}
		_memset((void *)&head, 0, sizeof(head));
		return (NULL);
	}
	fb = get_struct(&head, fd);
	if (fb)
		line = read_buf(fb);
	if (line && line[0] == '\n' && !line[1])
		line[0] = 0;
	return (line);
}

/**
 * get_struct - adds a struct to linked list
 * @head: pointer to head node
 * @fd: file descriptor of struct to get
 * Return: pointer to a struct
 */
FILE_T *get_struct(FILE_T *head, const int fd)
{
	FILE_T *node;

	if (!head->buf && !head->fd && !head->next)
	{
		head->fd = fd;
		return (head);
	}
	for (; head->next && head->next->fd <= fd; head = head->next)
		;
	if (head->fd == fd)
		return (head);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	if (fd < head->fd)
	{
		memcpy(node, head, sizeof(*head));
		memset(head, 0, sizeof(*head));
		head->fd = fd;
		head->next = node;
		return (head);
	}
	memset(node, 0, sizeof(*node));
	node->fd = fd;
	node->next = head->next;
	head->next = node;
	return (node);
}

/**
 * read_buf - reads into buffer
 * @frame: a struct with buffer
 *
 * Return: pointer to the line in buffer
 */
char *read_buf(FILE_T *frame)
{
	char buf[READ_SIZE + 1], *p, *line;
	ssize_t count = 0;

	p = find_char(frame->buf + frame->i, '\n', frame->len - frame->i);
	if (!frame->len || frame->i >= frame->len || !p)
	{
		while (1)
		{
			count = read(frame->fd, buf, READ_SIZE);
			if (count < 0 || (count == 0 && !frame->len))
				return (frame->buf ? (free(frame->buf), NULL) : NULL);
			if (count == 0)
			{
				p = frame->buf + frame->len;
				break;
			}
			frame->buf = _realloc(frame->buf, frame->len, frame->len + count + 1);
			if (!frame->buf)
				return (NULL);
			_memcpy((void *)(frame->buf + frame->len), buf, count), frame->len += count;
			p = find_char(frame->buf + (frame->len - count), '\n', count);
			if (p)
			{
				frame->buf[frame->len] = 0;
				break;
			}
		}
	}
	*p = '\0';
	line = malloc(1 + (p - (frame->buf + frame->i)));
	if (!line)
		return (NULL);
	_memcpy((void *)line, frame->buf + frame->i, 1 + (p - (frame->buf + frame->i)));
	frame->i = (p - frame->buf) + 1;
	if (frame->i >= frame->len)
	{
		frame->i = frame->len = 0;
		frame->buf = (free(frame->buf), NULL);
	}
	return (line);
}

/**
 * find_char - finds a character in a string
 * @str: pointer to string
 * @c: character to locate
 * @size: byte count of string
 * Return: pointer to memory location.
 */
char *find_char(char *str, char c, ssize_t size)
{
	if (!str)
		return (NULL);
	do {
		if (*str == c)
			return (str);
		str++;
	} while (--size > 0);
	return (NULL);
}

/**
 * _realloc - uses malloc to reallocate a block of memory
 * @prev: pointer to previous malloc'ed memory
 * @last: byte size of current block
 * @new: byte size of new block
 * Return: pointer to new block
 */
void *_realloc(void *prev, unsigned int last, unsigned int new)
{
	char *ptr;

	if (!prev)
		return (malloc(new));
	if (!new)
		return (free(prev), NULL);
	if (new == last)
		return (prev);
	ptr = malloc(new);
	if (!ptr)
		return (NULL);

	last = last < new ? last : new;
	while (last--)
		ptr[last] = ((char *) prev)[last];
	free(prev);
	return (ptr);
}
