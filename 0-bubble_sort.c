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
	unsigned int x, y;
	int temp;

	/* Check if the array has less than 2 elements */
	if (size < 2)
		return;

	/* Iterate through the array */
	for (x = 0; x < size; x++)
	{
		/* Iterate through the unsorted part of the array */
		for (y = 0; y < size - x - 1; y++)
		{
			/* If current element is greater than the next one, swap them */
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}
}
