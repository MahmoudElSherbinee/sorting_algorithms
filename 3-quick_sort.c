#include "sort.h"

/**
 * quick_sort - function sorts an array of integers
 * in ascending order using the quicksort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	/* If the array has less than 2 elements, it's already sorted */
	if (size < 2)
		return;

	/* Apply quicksort recursively to the entire array */
	quick_sort_recursive(array, 0, (int)size - 1, size);
}
