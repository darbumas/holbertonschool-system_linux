#include "hls.h"
/**
 * error_handler - handles errors
 * @val: return value for syscalls
 * @err_file: file stream that generated the error
 * Return: Nothing
 */
void error_handler(int val, char *err_file)
{
	char *buf, *dirErr, *accessErr, *strErr;

	dirErr = "./hls: cannot open direct %s";
	accessErr = "./hls: cannot access %s";

	if (val == EACCES)
		strErr = dirErr;
	else
		strErr = accessErr;
	buf = malloc(256);
	sprintf(buf, strErr, *err_file);
	perror(buf);
	free(buf);
}
