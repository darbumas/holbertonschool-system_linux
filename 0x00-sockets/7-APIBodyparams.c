#include "httprotocol.h"

/**
 * main - program entry
 * Return: SUCCESS or FAILURE
 */
int main(void)
{
	return (server_start());
}
/**
 * trimwhitespace - trims whitespaces.
 * @ogstring: pointer to the original string.
 * Return: pointer to a substring without the whitespaces, or NULL.
 */
char *trimwhitespace(char *ogstring)
{
	ssize_t i;

	if (!ogstring)
		return (NULL);
	while (isspace((unsigned char)*ogstring))
		ogstring++;
	for (i = strlen(ogstring) - 1; i >= 0; i--)
	{
		if (!isspace((unsigned char)ogstring[i]))
			break;
		ogstring[i] = 0;
	}
	return (ogstring);
}
/**
 * parse_request - parses HTTP headers and prints fields.
 * @client_id: client socket descriptor
 * @buffer: buffer containing received message
 * Return: 0 on success, otherwise 1
 */
int parse_request(int client_id, char *buffer)
{
	char *saveptr1, *saveptr2, *path, *next_token, *query;
	char *header, *body, *key, *val;
	char *type = "Content-Type";
	char *encoding = "application/x-www-form-urlencoded";
	int flag = 0;

	body = strstr(buffer, CRLF CRLF);
	if (strlen(body))
	{
		*body = 0;
		body += strlen(CRLF CRLF);
	}
	next_token = strtok_r(buffer, CRLF, &saveptr1);
	strtok(next_token, " \t");
	path = strtok(NULL, " \t");
	path = strtok(path, "?");
	printf("Path: %s\n", path);
	header = strtok_r(NULL, CRLF, &saveptr1);
	while (header)
	{
		key = trimwhitespace(strtok_r(header, ":", &saveptr2));
		val = trimwhitespace(strtok_r(NULL, CRLF, &saveptr2));
		if (!strcasecmp(key, type))
		{
			if (!strcasecmp(val, encoding))
				flag = 1;
		}
		header = strtok_r(NULL, CRLF, &saveptr1);
	}
	if (flag)
	{
		query = strtok_r(body, "&", &saveptr1);
		while (query)
		{
			key = strtok_r(query, "=", &saveptr2);
			val = strtok_r(NULL, "=", &saveptr2);
			printf("Body param: \"%s\" -> \"%s\"\n", key, val);
			query = strtok_r(NULL, "&", &saveptr1);
		}
	}
	send_response(client_id, "HTTP/1.1 200 OK\n\n");
	return (0);
}
