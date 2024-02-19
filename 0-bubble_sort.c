#include "sort.h"

/**
 * bubble_sort - function sorts an array of integers
 * in ascending order using the bubble sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int temp;

	/* Check if the array has less than 2 elements */
	if (size < 2)
		return;

	/* Iterate through the array */
	for (i = 0; i < size; i++)
	{
		/* Iterate through the unsorted part of the array */
		for (j = 0; j < size - i - 1; j++)
		{
			/* If current element is greater than the next one, swap them */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
