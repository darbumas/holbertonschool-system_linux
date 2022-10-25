#include "hls.h"
/**
 * sort - returns an array of strings
 * Description: this function sort files
 * @files: double pointer to the arguments passed
 * @mode: how info sorted
 * @folder: which way is the info sorted
 * Return: a pointer to first string with all the valid args
 */
char **sort(char **files, int mode, char *folder)
{
	file_t *file = NULL;

	file = create_list(files, folder);

	if (mode == 2)
		reverse(&file);
	if (mode == 3)
	{
		sortby_time(&file);
		reverse(&file);
	}
	if (mode == 4)
	{
		sortby_size(&file);
		reverse(&file);
	}
	files = create_array(&file);

	free_list(&file);
	return (files);
}
/**
 * reverse - converts array to a DL list
 * @head: the head of list
 * Return: Nothing.
 **/
void reverse(file_t **head)
{
	file_t *temp = NULL;
	file_t *current = *head;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp != NULL)
		*head = temp->prev;
}
/**
 * sortby_size - insertion sort algorithm
 * @list: linked list
 * Return: Nothing
 */
void sortby_size(file_t **list)
{
	file_t *aux, *tail, *head, *swap_1, *swap_2, *aux_1, *aux_2;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (head != NULL && head->next != NULL)
	{
		if (head->size > head->next->size)
		{
			swap_1 = head, swap_2 = head->next;
			aux_1 = swap_1->prev, aux_2 = swap_2->next;
			if (aux_1 != NULL)
				aux_1->next = swap_2;
			else
				*list = swap_2;
			aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
			swap_2->prev = aux_1, swap_1->next = aux_2;
			swap_2->next = swap_1, swap_1->prev = swap_2;
			tail = head, head = head->prev;
			while (head && head->prev)
			{
				aux = head;
				if (aux->size < aux->prev->size)
				{
					swap_1 = aux->prev, swap_2 = aux;
					aux_1 = swap_1->prev, aux_2 = swap_2->next;
					if (aux_1 != NULL)
						aux_1->next = swap_2;
					else
						*list = swap_2;
					aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
					swap_2->prev = aux_1, swap_1->next = aux_2;
					swap_2->next = swap_1, swap_1->prev = swap_2;
				}
				else
					break;
			} head = tail;
		} else
			head = head->next;
	}
}
/**
 * sortby_time - insertion sort algorithm
 * @list: linked list
 * Return: void
 */
void sortby_time(file_t **list)
{
	file_t *aux, *tail, *head, *swap_1, *swap_2, *aux_1, *aux_2;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (head != NULL && head->next != NULL)
	{
		if (head->time > head->next->time)
		{
			swap_1 = head, swap_2 = head->next;
			aux_1 = swap_1->prev, aux_2 = swap_2->next;
			if (aux_1 != NULL)
				aux_1->next = swap_2;
			else
				*list = swap_2;
			aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
			swap_2->prev = aux_1, swap_1->next = aux_2;
			swap_2->next = swap_1, swap_1->prev = swap_2;
			tail = head, head = head->prev;
			while (head && head->prev)
			{ aux = head;
				if (aux->time < aux->prev->time)
				{
					swap_1 = aux->prev, swap_2 = aux;
					aux_1 = swap_1->prev, aux_2 = swap_2->next;
					if (aux_1 != NULL)
						aux_1->next = swap_2;
					else
						*list = swap_2;
					aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
					swap_2->prev = aux_1, swap_1->next = aux_2;
					swap_2->next = swap_1, swap_1->prev = swap_2;
				}
				else
					break;
			} head = tail;
		} else
			head = head->next;
	}
}

