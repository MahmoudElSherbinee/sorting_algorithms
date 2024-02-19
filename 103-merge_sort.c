#include "sort.h"

/**
 * subarray_merger - function merges two subarrays
 * into a single sorted subarray.
 * This function merges two subarrays within the given array
 * into a single sorted subarray.
 * The subarrays to be merged are defined by the indices
 * [left, middle) and [middle, right).
 *
 * @merged_array: The auxiliary array used for merging and storing the result.
 * @original_array: The array containing the elements to be merged.
 * @left: The left index of the first subarray.
 * @middle: The right index of the first subarray
 * and the left index of the second subarray.
 * @right: The right index of the second subarray.
 */
void subarray_merger(int *merged_array, int *original_array, size_t left,
					size_t middle, size_t right)
{
	size_t x, y, z = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(original_array + left, middle - left);
	printf("[right]: ");
	print_array(original_array + middle, right - middle);

	for (x = left, y = middle; x < middle && y < right; z++)
	{
		if (original_array[x] < original_array[y])
			merged_array[z] = original_array[x++];
		else
			merged_array[z] = original_array[y++];
	}

	while (x < middle)
		merged_array[z++] = original_array[x++];
	while (y < right)
		merged_array[z++] = original_array[y++];

	for (z = left, x = 0; z < right; z++)
		original_array[z] = merged_array[x++];

	printf("[Done]: ");
	print_array(original_array + left, right - left);
}

/**
 * recursion_merger - function recursively merges subarrays
 * within the given array.
 * This function recursively merges subarrays within the given array
 * until the entire array is sorted.
 * It uses the merge sort algorithm to accomplish this task.
 *
 * @merged_array: The auxiliary array used for merging and storing the result.
 * @original_array: The array containing the elements to be sorted.
 * @left: The left index of the current subarray.
 * @right: The right index of the current subarray.
 */
void recursion_merger(int *merged_array, int *original_array,
														size_t left, size_t right)
{
	size_t middle;

	/* Check if there are at least two elements in the subarray */
	if (right - left > 1)
	{
		/* Calculate the middle index of the subarray */
		middle = (right - left) / 2 + left;

		/* Recursively merge the left subarray */
		recursion_merger(merged_array, original_array, left, middle);

		/* Recursively merge the right subarray */
		recursion_merger(merged_array, original_array, middle, right);

		/* Merge the two sorted subarrays */
		subarray_merger(merged_array, original_array, left, middle, right);
	}
}

/**
 * merge_sort - function sorts an array of integers
 * using the merge sort algorithm.
 * This function sorts an array of integers in non-decreasing order
 * using the merge sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *auxiliary_array;

	/* Check if array is valid or has less than 2 elements */
	if (!array || size < 2)
		return;

	/* Allocate memory for the auxiliary array */
	auxiliary_array = malloc(sizeof(int) * size);

	/* Perform merge sort recursively */
	recursion_merger(auxiliary_array, array, 0, size);

	/* Free allocated memory */
	free(auxiliary_array);
}
