#include "laps.h"

void join_race(racecar **head, int id);

/**
 * race_state - keeps track of the number of laps
 * made by several cars in a race.
 * @id: array of int representing unique 'id' of each car.
 * @size: size of the array.
 */
void race_state(int *id, size_t size)
{
	static racecar *head;
	racecar *temp = NULL;
	size_t i;

	if (!size)
	{
		while (head)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		return;
	}
	for (i = 0; i < size; i++)
		join_race(&head, id[i]);

	printf("Race state:\n");
	for (temp = head; temp; temp = temp->next)
		printf("Car %d [%d laps]\n", temp->id, temp->laps);
}

/**
 * join_race - keeps track of cars joining the race
 * @head: node to the first car
 * @id: car identifier
 */

void join_race(racecar **head, int id)
{
	racecar *car = NULL;
	racecar *temp = NULL;

	if (!*head || id < (*head)->id)
	{
		car = malloc(sizeof(racecar));
		if (!car)
			exit(EXIT_FAILURE);
		car->id = id;
		car->laps = 0;
		car->next = *head;
		*head = car;
		printf("Car %d joined the race\n", id);
		return;
	}
	for (car = *head; car->next && car->next->id <= id; car = car->next);

	if (car->id == id)
	{
		car->laps++;
		return;
	}
	temp = malloc(sizeof(racecar));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->id = id;
	temp->laps = 0;
	temp->next = car->next;
	car->next = temp;
	printf("Car %d joined the race\n", id);
}
