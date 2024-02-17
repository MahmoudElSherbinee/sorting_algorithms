#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Structs */

/* Main Structs */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* My Structs */

/* Functions */
void bubble_sort(int *arr, size_t s);


/* Main functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* My functions */


#endif /* SORT_H */


