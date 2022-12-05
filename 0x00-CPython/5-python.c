#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_int - prints Python integers
 * @p: pointer to a Python obj (string)
 */
void print_python_int(PyObject *p)
{
	ssize_t size, i, neg;
	unsigned long n = 0, sub;
	int sh;

	setbuf(stdout, NULL);
	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;
	neg = size < 0;
	size = neg ? -size : size;
	if (size > 3 || (size == 3 && ((PyLongObject *)p)->ob_digit[2] > 0xf))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	for (i = 0; i < size; i++)
	{
		sh = PyLong_SHIFT * i;
		sub = ((unsigned long)((PyLongObject *)p)->ob_digit[i]) * (1UL << (sh));
		n += sub;
	}
	if (neg)
		printf("-");
	printf("%lu\n", n);
}
