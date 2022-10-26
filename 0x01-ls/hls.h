#ifndef HLS_H
#define HLS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include <sys/sysmacros.h>

/**
 * struct file_s - doubly linked list
 * @var: pointer to env. variables
 * @size: variable
 * @time: variable
 * @next: points to the next node
 * @prev: points to the prev node
 */
typedef struct file_s
{
	char *var;
	long int size;
	unsigned long int time;
	struct file_s *prev;
	struct file_s *next;
} file_t;

/* Memory management */
void *_calloc(unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* DIR */
char *validate_args(char **, char **);
char **locate_folder(int, char **, int *, int *, int *, int *, char *);
char **validate_dir(int, char **, int *, int *, int *, int *, char *);
char **read_dir(DIR *, char *, int *, char **);
int print_dir(char **, char *, char *);
DIR *open_dir(char *);

/* Utilities */
bool confirm(char *, char);
char *permissions(struct stat);
char *get_date(struct stat);
long int parse_date(struct stat);

/* String operators */
int _strlen(char *s);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *s0, char *s1);
char *_strstr(char *, char *);
unsigned long int _atoi(char *);

/* Options */
void option_l(char **, char *, char **);
char **option_a(char **, char *);
char **option_A(char **, char *);
void option_1(char **, char *, char **);
void no_option(char **, char *, char **);

/* Sorting operators */
char **sort(char **, int, char *);
void reverse(file_t **);
void sortby_size(file_t **);
void sortby_time(file_t **);

/* Sort helper functions */
file_t *create_list(char **, char *);
char **create_array(file_t **);
int _index(char *, char);
char select_sort(char *);

/* Linked lists */
file_t *add_node(file_t **, char *, struct stat);
size_t print_list(file_t **);
void free_list(file_t **);
int delete_node(file_t **, unsigned int);
int get_nodes(char **, char *);

#endif
