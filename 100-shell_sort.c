#include "sort.h"

/**
 * shell_sort - function sorts an array of integers
 * in ascending order using the shell sort algorithm.
 * Shell sort is an in-place comparison sort algorithm that starts by sorting
 * pairs of elements far apart from each other, then progressively reducing the
 * gap between elements to be compared, thus improving the efficiency of
 * insertion sort.
 * The algorithm chooses the gap sequence to be used and performs
 * multiple passes over the array,
 * each time sorting elements with a certain gap.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, x, y;
	int temp;

	/* If the array has less than 2 elements, it's already sorted */
	if (size < 2)
		return;

	/* Determine the initial gap sequence for shell sort */
	while ((gap = gap * 3 + 1) < size)
		;

	/* Adjust the gap to fit within the array bounds */
	gap = (gap - 1) / 3;

	/* Iterate over the gap sequence */
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		/* Perform insertion sort for elements at each gap interval */
		for (x = gap; x < size; x++)
		{
			temp = array[x];
			/* Perform insertion sort for elements at the current gap interval */
			for (y = x; y >= gap && temp <= array[y - gap]; y -= gap)
				array[y] = array[y - gap];
			array[y] = temp;
		}
		/* Print the array after each gap interval */
		print_array(array, size);
	}
}
