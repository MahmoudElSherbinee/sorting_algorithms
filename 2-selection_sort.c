#include "sort.h"

/**
 * selection_sort - function sorts an array of integers
 * in ascending order using the selection sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	/* Loop indices and variable to store index of minimum value */
	unsigned int i, j, minimum;

	int temp; /* Temporary variable for swapping values */

	/* Check if the array has less than 2 elements */
	if (size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size; i++)
	{
		minimum = i; /* Assume the minimum value is at index i */

		/* Find the index of the minimum value in the unsorted part of the array */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minimum])
				minimum = j;
		}

		/* Swap the minimum value with the value at index i */
		temp = array[i];
		array[i] = array[minimum];
		array[minimum] = temp;

		/* If a swap occurred, print the array */
		if (i != minimum)
			print_array(array, size);
	}
}
