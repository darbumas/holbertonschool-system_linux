#include "hls.h"
/**
 * main - program start
 * @argc: argument count
 * @argv: argument pointers
 *
 * Return: 1 upon success, -1 otherwise
 */

int main(int argc, char **argv)
{
	char **param;
	char *flags;
	int res, paramCnt, flagCnt;

	param = malloc(sizeof(char **) * argc);
	flags = malloc(sizeof(char *) * argc);

	flagCnt = flagcount(flags, argc, argv);
	paramCnt = filecount(param, argv, argc);
	res = dirread(flags, param, flagCnt, paramCnt);

	free(param);
	free(flags);
	return (res);
}
