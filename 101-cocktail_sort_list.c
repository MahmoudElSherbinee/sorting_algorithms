#include "sort.h"

/**
 * list_length - function calculates the length of a singly linked list.
 *
 * @head: Pointer to the head of the linked list.
 *
 * Return: The length of the linked list.
 */
size_t list_length(listint_t *head)
{
	size_t length = 0;

	/* Traverse the linked list */
	while (head)
	{
		length++;
		head = head->next;
	}

	return (length);
}

/**
 * node_swicher - function switches the position of a node
 * with its next node in a doubly linked list.
 * This function switches the position of a given node (*ptr)
 * with its next node in a doubly linked list.
 * If the given node is the first node of the list,
 * the list pointer (*list) is updated accordingly.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 * @ptr: A pointer to a pointer to the node to be switched.
 */
void node_swicher(listint_t **list, listint_t **ptr)
{
	/* Declare variables to hold references to relevant nodes */
	listint_t *prev_node, *current_node, *next_node, *next_next_node;

	/* Assign references to nodes */
	prev_node = (*ptr)->prev;
	current_node = *ptr;
	next_node = (*ptr)->next;
	next_next_node = (*ptr)->next->next;

	/* Adjust pointers to switch the nodes */
	current_node->next = next_next_node;
	if (next_next_node)
		next_next_node->prev = current_node;
	next_node->next = current_node;
	next_node->prev = current_node->prev;
	if (prev_node)
		prev_node->next = next_node;
	else
		*list = next_node;
	current_node->prev = next_node;
	*ptr = next_node;
}

/**
 * cocktail_sort_list - function sorts a doubly linked list
 * using the cocktail shaker (bidirectional bubble sort) algorithm.
 *
 * This function sorts a doubly linked list in ascending order
 * using the cocktail shaker algorithm.
 * It repeatedly iterates over the list bidirectionally,
 * swapping adjacent elements if they are in the wrong order.
 *
 * @list: A pointer to a pointer to the head of
 * the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node; /* Declare variables */
	int sorted = 0;
	/* Check if list is empty or has only one element */
	if (!list || !*list || list_length(*list) < 2)
		return;
	current_node = *list; /* Initialize current_node to the head of the list */
	while (!sorted) /* Iterate until the list is sorted */
	{
		sorted = 1; /* Assume the list is sorted */
		while (current_node->next) /* Traverse the list from left to right */
		{
			/* If current node is greater than the next node, swap them */
			if (current_node->n > current_node->next->n)
			{
				sorted = 0; /* Mark the list as not sorted */
				node_swicher(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->next;
		}
		if (sorted) /* If the list is sorted, exit the loop */
			break;
		current_node = current_node->prev;/* Move current_node to the previous node*/
		while (current_node->prev) /* Traverse the list from right to left */
		{
			/* If current node is less than the previous node, swap them */
			if (current_node->n < current_node->prev->n)
			{
				sorted = 0; /* Mark the list as not sorted */
				/* Move current_node to the previous node, */
				/* swap the adjacent nodes, and print the list */
				current_node = current_node->prev;
				node_swicher(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->prev;
		}
	}
}
