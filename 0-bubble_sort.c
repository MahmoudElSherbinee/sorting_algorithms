#include "sort.h"

void bubble_sort(int *arr, size_t s)
{
	unsigned int x, y;
	int temproray;

	if (s < 2)
		return;

	for (x = 0; x < s; x++)
	{
		for (y = 0; y < s - x - 1; y++)
		{
			if (arr[y] > arr[y + 1])
			{
				temproray = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temproray;
				print_arr(arr, s);
			}
		}
	}
}
