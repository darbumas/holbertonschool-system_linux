/**
 * _strncmp - compares two strings
 * @str0: points to the first string
 * @str1: points to the second string
 * @n: most bytes in str0 & str1 to compare
 *
 * Return: 0 if same
 */

int _strncmp(char *str0, char *str1, int n)
{
	int i;
	int flag = 0;

	for (i = 0; i < n; i++)
	{
		if (str0[i] != str1[i])
		{
			flag = i + 1;
			break;
		}
	}
	return (flag);
}
