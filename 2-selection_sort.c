#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: integer a
 * @b: integer b
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order.
 * @array: The array to be sorted
 * @size: The size of the array.
 *
 * Description: Sorts by comparing an element in an array to the next element
 * swapping them depending on their size. Prints the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_pos = 0;
	/* bool latch = true; */

	if (array == NULL || size < 2)
		return;

	for (i = 0; i <= size - 1 /* && latch == true*/; i++)
	{
		/* min = array[i]; */
		min_pos = i;
		/* latch = false; */
		for (j = i; j <= size - 1; j++)
		{
			if (array[j] < array[min_pos])
			{
				/* min = array[j]; */
				min_pos = j;
				/* latch = true; */
			}
		}
		if (min_pos != i)
		{
			swap_ints(&array[i], &array[min_pos]);
			print_array(array, size);
		}
	}
}
