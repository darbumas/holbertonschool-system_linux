#ifndef _LAPS_H_
#define _LAPS_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct car - structure that defines a car
 * @id: unique ID of each car
 * @laps: lap count
 * @next: points to the next car
 */
typedef struct car
{
	int id;
	int laps;
	struct car *next;
} racecar;

void race_state(int *id, size_t size);

#endif
