#ifndef DECK_H
#define DECK_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Structs */

/* Main Structs */
/**
 * enum kind_e - kinds
 * @SPADE: spade
 * @HEART: heart
 * @CLUB: club
 * @DIAMOND: diamond
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Functions */
size_t count_nodes_deck(deck_node_t *list);
int compare_strings(const char *str1, const char *str2);
int value_of_cards(deck_node_t *node);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
