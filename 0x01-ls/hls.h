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

#endif
