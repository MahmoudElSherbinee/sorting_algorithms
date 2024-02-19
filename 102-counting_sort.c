#include "sort.h"

/**
 * counting_sort - function sorts an array of integers
 * using the counting sort algorithm.
 * This function sorts an array of integers in non-decreasing order
 * using the counting sort algorithm.
 * Counting sort assumes that each of the input elements
 * is an integer in a small range.
 *
 * @array: A pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	/* Declare variables */
	int *count, *output, maximum, value, a, b;
	size_t w, x, y, z;

	/* Check if array has less than 2 elements */
	if (size < 2)
		return;

	/* Find the maximum element in the array */
	maximum = array[0];
	for (w = 1; w < size; w++)
		if (array[w] > maximum)
			maximum = array[w];
	/* Allocate memory for count and output arrays */
	count = malloc(sizeof(int) * (maximum + 1));
	output = malloc(sizeof(int) * size);
	/* Initialize count array with zeros */
	for (a = 0; a <= maximum; a++)
		count[a] = 0;
	/* Count occurrences of each element in the array */
	for (x = 0; x < size; x++)
	{
		value = array[x];
		count[value] += 1;
	}
	/* Calculate cumulative sum of counts */
	for (b = 1; b <= maximum; b++)
		count[b] += count[b - 1];
	print_array(count, maximum + 1);
	/* Place elements in their correct positions in output array */
	for (y = 0; y < size; y++)
	{
		output[count[array[y]] - 1] = array[y];
		count[array[y]]--;
	}
	/* Copy sorted elements back to the original array */
	for (z = 0; z < size; z++)
		array[z] = output[z];
	free(count); /* Free allocated memory */
	free(output); /* Free allocated memory */
}
