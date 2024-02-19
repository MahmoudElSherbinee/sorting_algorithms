#include "sort.h"

/**
 * partition_array - function divides an array into two parts
 * for the quicksort algorithm.
 *
 * @array: Pointer to the array to be divided.
 * @left_index: Index of the left boundary of the division.
 * @right_index: Index of the right boundary of the division.
 * @array_size: Size of the array.
 *
 * Return: The index of the pivot element after division.
 */
int partition_array(int *array, int left_index,
					int right_index, size_t array_size)
{
	int temporary, pivot_index;
	int iterator;

	pivot_index = left_index - 1;

	/* Iterate through the division */
	for (iterator = left_index; iterator < right_index; iterator++)
	{
		/* If the current element is less than the pivot */
		if (array[iterator] < array[right_index])
		{
			pivot_index++;
			if (pivot_index != iterator)
			{
				/* Swap elements */
				temporary = array[pivot_index];
				array[pivot_index] = array[iterator];
				array[iterator] = temporary;
				/* Print the array after each swap */
				print_array(array, array_size);
			}
		}
	}

	/* Swap the pivot element to its correct position */
	if (array[right_index] < array[pivot_index + 1])
	{
		temporary = array[pivot_index + 1];
		array[pivot_index + 1] = array[right_index];
		array[right_index] = temporary;
		/* Print the array after each swap */
		print_array(array, array_size);
	}

	return (pivot_index + 1);
}

/**
 * quick_sort_recursive - function recursively applies
 * the quicksort algorithm to sort an array of integers.
 *
 * @array: Pointer to the array to be sorted.
 * @left_index: Index of the left boundary of the partition.
 * @right_index: Index of the right boundary of the partition.
 * @array_size: Size of the array.
 */
void quick_sort_recursive(int *array, int left_index,
													int right_index, size_t array_size)
{
	int pivot_index;

	/* If the left boundary is less than the right boundary */
	if (left_index < right_index)
	{
		/* Partition the array and obtain the pivot index */
		pivot_index = partition_array(array, left_index, right_index, array_size);

		/* Apply quicksort recursively to the left partition */
		quick_sort_recursive(array, left_index, pivot_index - 1, array_size);

		/* Apply quicksort recursively to the right partition */
		quick_sort_recursive(array, pivot_index + 1, right_index, array_size);
	}
}
