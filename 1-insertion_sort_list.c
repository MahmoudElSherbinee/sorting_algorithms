#include "sort.h"

/**
 * length_of_linked_list - function calculates the length of a linked list.
 *
 * @head: Pointer to the head of the linked list.
 *
 * Return: The length of the linked list.
 */
int length_of_linked_list(listint_t *head)
{
	int length = 0; /* Initialize the length counter */

	/* Traverse the linked list */
	while (head)
	{
		length++;		   /* Increment the length counter */
		head = head->next; /* Move to the next node */
	}

	return (length); /* Return the length of the linked list */
}

/**
 * insertion_sort_list - function sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm.
 *
 * @list: Double pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *first = NULL;
	listint_t *second = NULL, *third = NULL, *fourth = NULL;

	/* Check if the list is valid and has at least 2 elements */
	if (!list || !(*list) || length_of_linked_list(*list) < 2)
		return;
	/* Initialize current pointer to the head of the list */
	current = *list;
	while (current) /* Iterate through the list */
	{
		/* If current node is out of order */
		if (current->prev && current->n < current->prev->n)
		{
			/* Store references to nodes involved in the swap */
			first = current->prev->prev;
			second = current->prev;
			third = current;
			fourth = current->next;
			second->next = fourth; /* Perform the swap */
			if (fourth)
				fourth->prev = second;
			third->next = second;
			third->prev = first;
			if (first)
				first->next = third;
			else
				*list = third;
			second->prev = third;
			/* Reset current pointer to the head of the list */
			current = *list;
			/* Print the list after each swap */
			print_list(*list);
			continue;
		}
		else
		{
			/* Move to the next node */
			current = current->next;
		}
	}
}
