#include "hls.h"

/**
 * validate_args - reads the argv and selects valid arguments
 * @argv: array of strings passed as arguments
 * @err: array of strings
 * Return: pointer to a string with valid args
 */
char *validate_args(char **argv, char **err)
{
	int i, j;
	char *valid = "1aAlrStR", str[2];
	char *args = NULL;
	char buf[120] = {'-', '\0'};

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '-' && _strstr(argv[i], "--") == NULL)
		{
			for (j = 1; argv[i][j] != '\0'; j++)
				if (confirm(valid, argv[i][j]))
				{
					if (!confirm(buf, argv[i][j]))
						str[0] = argv[i][j], str[1] = '\0', _strcat(buf, str);
					continue;
				}
				else
				{
					fprintf(stderr,
					"hls: invalid option -- '%c'\nTry 'hls --help' for more information.\n",
					argv[i][j]);
					free(err);
					exit(2);
				}
		}
		if (_strstr(argv[i], "---") != NULL)
		{
			fprintf(stderr,
			"hls: unrecognized option '---'\nTry 'hls --help' for more information.\n");
			free(err), exit(2);
		}
	}
	if (_strlen(buf) != 0)
	{
		args = _strdup(buf);
		return (args);
	}
	return (NULL);
}
