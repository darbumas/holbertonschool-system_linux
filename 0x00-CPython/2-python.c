#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_list - prints basic info about Python lists
 * @p: pointer to a python object (list)
 *
 * Return: Nothing
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i = 0;

	printf("[*] Python list info\n"
			"[*] Size of the Python List = %li\n"
			"[*] Allocated = %li\n",
			Py_SIZE(p), ((PyListObject *) p)->allocated);
	while (i < Py_SIZE(p))
	{
		printf("Element %li: %s\n",
				i, Py_TYPE((PyList_GetItem(p, i)))->tp_name);
		i++;
	}
}

/**
 * print_python_bytes - print basic info about Python byte objects
 * @p: pointer to a Python object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	char *s;

	puts("[.] bytes object info");
	if (!PyBytes_Check(p))
	{
		puts("  [ERROR] Invalid Bytes Object");
		return;
	}
	size = PyBytes_Size(p);
	s = PyBytes_AsString(p);
	printf("  size: %li\n"
			"  trying string: %s\n"
			"  first %li bytes:",
			size, s, size < 10 ? size + 1 : 10);
	for (i = 0; i <= size && i < 10; ++i)
		printf(" %02hhx", s[i]);
	putchar('\n');
}
