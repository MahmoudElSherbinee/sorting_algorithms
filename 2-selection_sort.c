#include "sort.h"

void selection_sort(int *arr, size_t s)
{
	unsigned int x, y, minimum;

	register int temporary;

	if (s < 2)
		return;

	for (x = 0; x < s; x++)
	{
		minimum = x;
		for (y = x + 1; y < s; y++)
		{
			if (arr[y] < arr[minimum])
				minimum = y;
		}
		temporary = arr[x];
		arr[x] = arr[minimum];
		arr[minimum] = temporary;
		if (x != minimum)
			print_array(arr, s);
	}
}
