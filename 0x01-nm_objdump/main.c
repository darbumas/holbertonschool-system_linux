#include "hreadelf.h"

FILE *parse_args(int argc, char *argv[], int i);
void get_elf(FILE *fp, char *name, char *args, int *status);

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success, otherwise 1
 */
int main(int argc, char **argv)
{
	FILE *fp;
	int stat = 0, i = 1;

	do {
		fp = parse_args(argc, argv, i);
		if (!fp)
			stat = 1;
		else
			get_elf(fp, argv[0], argv[i], &stat);
	} while (++i < argc);
	return (stat);
}

/**
 * parse_args - checks for usage errors
 * @argc: count of arguments
 * @argv: arguments vector
 * @i: index for argv
 *
 * Return: pointer to file stream, otherwise NULL
 */
FILE *parse_args(int argc, char **argv, int i)
{
	FILE *fp;
	struct stat sb;

	if (argc == 1)
		argv[1] = "a.out";
	stat(argv[i], &sb);
	if (S_ISDIR(sb.st_mode))
	{
		fprintf(stderr, "%s: Warning: '%s' is a directory\n",
				argv[0], argv[i]);
		return (NULL);
	}
	fp = fopen(argv[i], "rb");
	if (!fp)
	{
		fprintf(stderr, "%s: '%s': No such file\n", argv[0], argv[i]);
		return (NULL);
	}
	return (fp);
}

/**
 * get_elf - get ELF information
 * @fp: pointer to file stream
 * @name: name of program
 * @args: pointer to name of file to get ELF information from
 * @status: current exit status to update accordingly
 */
void get_elf(FILE *fp, char *name, char *args, int *status)
{
	hdrs_t hdr;
	struct stat sb;

	memset(&hdr, 0, sizeof(hdr));
	if (stat(args, &sb))
		goto prnterr;
	hdr.addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE,
			fileno(fp), 0);
	if (hdr.addr == MAP_FAILED)
	{
prnterr:
		perror(NULL);
		goto out;
	}
	init_ehdr(&hdr);
	if (memcmp(hdr.Ehdr64->e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, "%s: %s: file format not recognized\n",
				name, args);
out:
		*status = 1;
		fclose(fp);
		return;
	}
	init_shdr(&hdr);
	if (!print_sym(&hdr))
		fprintf(stderr, "%s: %s: no symbols\n",
				name, args);
	fclose(fp);
}
