#include "sort.h"

/**
 * hoare_partition - function partitions an array into two parts
 * based on a pivot_index element.
 *
 * @array: Pointer to the array to be partitioned.
 * @left_index:  The left_index index of the hoare_partition.
 * @right_index: The right_index index of the hoare_partition.
 * @array_size:  The number of elements in the array.
 *
 * Return:      The index of the pivot_index element after partitioning.
 */
int hoare_partition(int *array, int left_index,
					int right_index, size_t array_size)
{
	int temp, pivot_index = array[right_index];
	size_t x = left_index - 1, y = right_index + 1;

	while (1)
	{
		/* Move the left_index pointer to the right_index */
		/* until finding an element greater than or equal to the pivot_index */
		do {
			x++;
		} while (array[x] < pivot_index);

		/* Move the right_index pointer to the left_index */
		/* until finding an element less than or equal to the pivot_index */
		do {
			y--;
		} while (array[y] > pivot_index);

		/* If the pointers cross, return the index of the pivot_index */
		if (x >= y)
			return (x);

		/* Swap the elements at the left_index and right_index pointers */
		if (x != y)
		{
			temp = array[x];
			array[x] = array[y];
			array[y] = temp;
			print_array(array, array_size);
		}
	}
	return (0); /* This line is unreachable */
}

/**
 * quick_sort_recursive - function recursively applies
 * the quicksort algorithm to sort an array of integers.
 *
 * @array: Pointer to the array to be sorted.
 * @left_index: Index of the left_index boundary of the hoare_partition.
 * @right_index: Index of the right_index boundary of the hoare_partition.
 * @array_size: Size of the array.
 */
void quick_sort_recursive(int *array, int left_index,
						  int right_index, size_t array_size)
{
	int pivot_index;

	/* If the left_index boundary is less than the right_index boundary */
	if (left_index < right_index)
	{
		/* Partition the array and obtain the pivot_index index */
		pivot_index = hoare_partition(array, left_index, right_index, array_size);

		/* Apply quicksort recursively to the left_index hoare_partition */
		quick_sort_recursive(array, left_index, pivot_index - 1, array_size);

		/* Apply quicksort recursively to the right_index hoare_partition */
		quick_sort_recursive(array, pivot_index, right_index, array_size);
	}
}

/**
 * quick_sort_hoare - function sorts an array of integers
 * using the Quick sort algorithm (Hoare hoare_partition scheme).
 *
 * @array: Pointer to the array to be sorted.
 * @array_size:  The number of elements in the array.
 */
void quick_sort_hoare(int *array, size_t array_size)
{
	/* Check if the array contains less than two elements */
	if (array_size < 2)
		return;

	/* Perform quick sort using the Hoare hoare_partition scheme */
	quick_sort_recursive(array, 0, (int)array_size - 1, array_size);
}
