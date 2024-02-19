#include "sort.h"

/**
 * modified_bitonic_merge - function performs a bitonic merge
 * on a section of an array.
 *
 * @array:      Pointer to the array.
 * @leftIndex:  The left index of the section to be merged.
 * @rightIndex: The right index of the section to be merged.
 * @dir:  The direction of the merge: 1 for ascending, 0 for descending.
 */
void modified_bitonic_merge(int *array, int leftIndex, int rightIndex, int dir)
{
	int temp, x;
	int step = (leftIndex + rightIndex) / 2;
	int middle = (rightIndex - leftIndex + 1) / 2;

	/* Check if the section contains more than one element */
	if (rightIndex - leftIndex >= 1)
	{
		/* Perform bitonic merge */
		for (x = leftIndex; x < leftIndex + middle; x++)
		{
			if (dir == (array[x] > array[x + middle]))
			{
				/* Swap elements if they are out of order based on the dir */
				temp = array[x + middle];
				array[x + middle] = array[x];
				array[x] = temp;
			}
		}
		/* Recursively perform bitonic merge on the left and right halves */
		modified_bitonic_merge(array, leftIndex, step, dir);
		modified_bitonic_merge(array, step + 1, rightIndex, dir);
	}
}

/**
 * bitonic_sort_recursion - function recursively performs bitonic sorting
 * on a section of an array.
 *
 * @array:      Pointer to the array.
 * @leftIndex:  The left index of the section to be sorted.
 * @rightIndex: The right index of the section to be sorted.
 * @direction:  The direction of sorting: 1 for ascending, 0 for descending.
 * @size:       The total size of the array.
 */
void bitonic_sort_recursion(int *array, int leftIndex,
							int rightIndex, int direction, size_t size)
{
	int step;

	/* Check if the section contains more than one element */
	if (rightIndex - leftIndex >= 1)
	{
		step = (rightIndex + leftIndex) / 2;
		printf("Merging [%d/%lu] ", rightIndex - leftIndex + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + leftIndex, rightIndex - leftIndex + 1);

		/* Recursively perform bitonic sorting on the left and right halves */
		bitonic_sort_recursion(array, leftIndex, step, 1, size);
		bitonic_sort_recursion(array, step + 1, rightIndex, 0, size);

		/* Merge the sorted halves */
		modified_bitonic_merge(array, leftIndex, rightIndex, direction);

		printf("Result [%d/%lu] ", rightIndex - leftIndex + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + leftIndex, rightIndex - leftIndex + 1);
	}
}

/**
 * bitonic_sort - function sorts an array of integers
 * using the Bitonic sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size:  The number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	/* Check if the array is empty or contains only one element */
	if (!array || size < 2)
		return;

	/* Perform bitonic sort recursively starting with an ascending order */
	bitonic_sort_recursion(array, 0, size - 1, 1, size);
}
