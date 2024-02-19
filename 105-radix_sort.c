#include "sort.h"

/**
 * Lsd_radix_sort - function sorts an array of integers
 * using the Least Significant Digit (LSD) radix sort algorithm.
 *
 * @inputArray: Pointer to the array to be sorted.
 * @size:       The number of elements in the array.
 * @lsd:        The least significant digit to start the sorting from.
 */
void Lsd_radix_sort(int *inputArray, size_t size, size_t lsd)
{
	/* Initialize an array to store the count of occurrences of each digit (0-9)*/
	int digitCount[10] = {0};
	/* Initialize pointers and loop variables */
	int *outputArray, x, y;
	size_t z, n;

	/* Allocate memory for the output array */
	outputArray = malloc(sizeof(int) * size);

	/* Count the occurrences of each digit */
	for (z = 0; z < size; z++)
		digitCount[(inputArray[z] / lsd) % 10]++;

	/* Calculate cumulative counts */
	for (x = 1; x < 10; x++)
		digitCount[x] += digitCount[x - 1];

	/* Rearrange the elements in the output array based on digit counts */
	for (y = size - 1; y >= 0; y--)
	{
		outputArray[digitCount[(inputArray[y] / lsd) % 10] - 1] = inputArray[y];
		digitCount[(inputArray[y] / lsd) % 10]--;
	}

	/* Copy sorted elements back to the original array */
	for (n = 0; n < size; n++)
		inputArray[n] = outputArray[n];

	/* Free dynamically allocated memory */
	free(outputArray);
}

/**
 * radix_sort - function sorts an array of integers
 * using the Radix sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size:       The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	size_t lsd, i;
	int max = 0;

	/* Check if the array is empty or contains only one element */
	if (!array || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Iterate through each digit position starting */
	/* from the least significant digit */
	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		/* Perform counting sort based on the current LSD */
		Lsd_radix_sort(array, size, lsd);
		/* Print the array after each iteration (optional, for visualization) */
		print_array(array, size);
	}
}
