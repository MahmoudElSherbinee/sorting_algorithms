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
/* Bubble Sort functions*/
void bubble_sort(int *arr, size_t s);

/* Insertion Sort functions */
int length_of_linked_list(listint_t *head);
void insertion_sort_list(listint_t **list);

/* Selection Sort functions*/
void selection_sort(int *array, size_t size);

/* Quick Sort functions */
int partition_array(int *array, int left_index,
												int right_index, size_t array_size);
void quick_sort_recursive(int *array, int left_index,
													int right_index, size_t array_size);
void quick_sort(int *array, size_t size);

/* Shell Sort functions */
void shell_sort(int *array, size_t size);

/* Cocktail Sort functions */
size_t list_length(listint_t *head);
void node_swicher(listint_t **list, listint_t **ptr);
void cocktail_sort_list(listint_t **list);

/* Counting Sort functions */
void counting_sort(int *array, size_t size);

/* Mrege Sort functions */
void subarray_merger(int *merged_array, int *original_array, size_t left,
					size_t middle, size_t right);
void recursion_merger(int *merged_array, int *original_array,
														size_t left, size_t right);
void merge_sort(int *array, size_t size);


/* Heap Sort functions */
void custom_heap(int *heap, size_t heap_size, size_t root, size_t array_size);
void heap_sort(int *array, size_t size);

/* Radix Sort functions */
void Lsd_radix_sort(int *inputArray, size_t size, size_t lsd);
void radix_sort(int *array, size_t size);

/* Bitonic Sort functions */
void modified_bitonic_merge(int *array, int leftIndex,
														int rightIndex, int dir);
void bitonic_sort_recursion(int *array, int leftIndex,
													int rightIndex, int direction, size_t size);
void bitonic_sort(int *array, size_t size);




/* Main functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* My functions */


#endif /* SORT_H */


