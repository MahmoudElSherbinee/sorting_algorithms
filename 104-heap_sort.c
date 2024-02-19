#include "sort.h"

/**
 * custom_heap - function heapifies a subtree rooted at a given index.
 * This function heapifies a subtree rooted at a given index
 * within the given array.
 * It ensures that the subtree satisfies the heap
 * property (either min-heap or max-heap).
 *
 * @heap: The array representing the heap.
 * @heap_size: The size of the heap.
 * @root: The index of the root of the subtree to be heapified.
 * @array_size: The total number of elements in the array.
 */
void custom_heap(int *heap, size_t heap_size, size_t root, size_t array_size)
{
	size_t max_index, left_child, right_child;
	int temp;

	max_index = root;
	left_child = (root * 2) + 1;
	right_child = (root * 2) + 2;

	/* Find the index of the maximum element among root, */
	/* left child, and right child */
	if (left_child < heap_size && heap[left_child] > heap[max_index])
		max_index = left_child;
	if (right_child < heap_size && heap[right_child] > heap[max_index])
		max_index = right_child;

	/* If the maximum element is not the root, */
	/* swap root with the maximum element and recursively custom_heap */
	if (max_index != root)
	{
		temp = heap[root];
		heap[root] = heap[max_index];
		heap[max_index] = temp;
		print_array(heap, array_size);
		custom_heap(heap, heap_size, max_index, array_size);
	}
}

/**
 * heap_sort - function sorts an array of integers
 * using the heap sort algorithm.
 * This function sorts an array of integers in non-decreasing order
 * using the heap sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int x, temp;

	/* Check if array has less than 2 elements */
	if (size < 2)
		return;

	/* Build max heap */
	for (x = size / 2 - 1; x >= 0; x--)
		custom_heap(array, size, (size_t)x, size);

	/* Extract elements from the heap one by one */
	for (x = size - 1; x >= 0; x--)
	{
		/* Swap the root (maximum element) with the last element */
		temp = array[x];
		array[x] = array[0];
		array[0] = temp;

		/* Print the array after each swap (except for the last swap) */
		if (x != 0)
			print_array(array, size);

		/* Heapify the reduced heap */
		custom_heap(array, (size_t)x, 0, size);
	}
}
