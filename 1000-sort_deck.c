#include "deck.h"

/**
 * count_nodes_deck - function counts
 * the number of nodes in a linked list.
 *
 * @list: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the linked list.
 */
size_t count_nodes_deck(deck_node_t *list)
{
	size_t length = 0;

	/* Iterate through the linked list and count nodes */
	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * compare_strings - function compares two strings.
 *
 * @str1: Pointer to the first string.
 * @str2: Pointer to the second string.
 *
 * Return:  An integer less than, equal to,
 *			or greater than zero if str1 is found,
 *          respectively, to be less than, to match,
 *			or be greater than str2.
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * value_of_cards - function determines the value of a card in a deck.
 *
 * @node: Pointer to the node containing the card.
 *
 * Return: The numerical value of the card.
 */
int value_of_cards(deck_node_t *node)
{
	char *value[13] = {"Ace", "2", "3", "4", "5", "6",
					   "7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kind[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, value_of_kind = 0;

	/* Determine the value of the card based on its face value */
	for (i = 0; i < 13; i++)
	{
		if (!compare_strings(node->card->value, value[i]))
			value_of_kind = i + 1;
	}

	/* Determine the value of the card based on its suit */
	for (i = 0; i < 4; i++)
	{
		if (!compare_strings(kind[node->card->kind], kind[i]))
			value_of_kind += 13 * (i + 1);
	}

	return (value_of_kind);
}

/**
 * sort_deck - function sorts a deck of cards
 * in ascending order based on their values.
 *
 * @deck: Pointer to the pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	size_t length;
	deck_node_t *first, *second, *third, *fourth;

	length = count_nodes_deck(*deck);	/* Calculate the length of the deck */
	/* Check if the deck is empty or contains only first card */
	if (!deck || !*deck || length < 2)
		return;
	/* Initialize the current pointer to the head of the deck */
	current = *deck;
	while (current)	/* Iterate through the deck */
	{
		/* Check if the current card needs to be moved */
		if (current->prev && value_of_cards(current) < value_of_cards(current->prev))
		{
			/* Adjust pointers to rearrange the cards */
			first = current->prev->prev;
			second = current->prev;
			third = current;
			fourth = current->next;

			second->next = fourth;
			if (fourth)
				fourth->prev = second;
			third->next = second;
			third->prev = first;
			if (first)
				first->next = third;
			else
				*deck = third;
			second->prev = third;
			/* Reset the current pointer to the head of the deck */
			current = *deck;
			continue;
		}
		else
		{
			current = current->next;	/* Move to the next card */
		}
	}
}
