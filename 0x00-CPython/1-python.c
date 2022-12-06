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
