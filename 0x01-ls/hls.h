#ifndef _HLS_HEADER_
#define _HLS_HEADER_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

/* String manipulation (helper func) */

int _strncmp(char *str0, char *str1, int n);
void lsFormat(struct dirent *read, char *flags, int flagCnt, struct stat statbuf);

int filecount(char **f_array, char **argv, int argc);
int flagcount(char *flags, int argc, char **argv);

int _readdir(DIR *dir, char *dir_name, char *flags, int flagCnt);
int dirread(char *flags, char **param, int flagCnt, int paramCnt);

void error_handler(int val, char *err_file);

#endif
