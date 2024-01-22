#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap function.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Perform Lomuto partition on an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot = array + high;
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (++i != j)
			{
				swap(array + i, array + j);
				print_array(array, size);
			}
		}
	}

	if (array[++i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - Implement quicksort.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition - 1);
		lomuto_sort(array, size, partition + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

