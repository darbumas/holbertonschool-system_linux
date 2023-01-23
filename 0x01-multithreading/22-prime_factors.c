#include "multithreading.h"

/**
 * create_task - creates a task
 * @entry: pointer to the entry function of the task
 * @param: parameter to be passed to the entry function
 * Return: pointer to the created task struct
 */
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *task = NULL;

	task = calloc(1, sizeof(*task));
	if (task == NULL)
	return (NULL);

	task->entry = entry;
	task->param = param;
	task->status = PENDING;
	return (task);
}

/**
 * destroy_task - terminates a task
 * @task: pointer to the task to terminate
 */
void destroy_task(task_t *task)
{
	if (task->result)
	{
		list_destroy((list_t *)task->result, free);
		free((list_t *)task->result);
	}
	free(task);
}

/**
 * exec_tasks - executes a list of tasks
 * @tasks: pointer to the list of tasks to be executed
 * Return: NULL
 */
void *exec_tasks(list_t const *tasks)
{
	int i = 0;
	task_t *task = NULL;
	node_t *ptr = tasks->head;

	while (ptr)
	{
		task = (task_t *)ptr->content;
		if (task->status == PENDING)
		{
			task->status = STARTED;
			tprintf("[%02d] Started\n", i);
			task->result = (void *)
			(((list_t * (*)(char const *)) task->entry)((char const *)task->param));
			tprintf("[%02d] Success\n", i);

			task->status = task->result ? SUCCESS : FAILURE;
		}
		i++;
		ptr = ptr->next;
	}
	return (NULL);
}
