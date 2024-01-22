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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: The array to be sorted
 * @size: The size of the array.
 *
 * Description: Sorts by comparing an element in an array to the next element
 * swapping them depending on their size. Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i <= size - 1; i++)
	{
		/* for (j = 0; j <= size - i - 1; j++) */
		/* { */
		/*	if (array[j] > array[j + 1]) */
		/*	{ */
		/*		swap_ints(&array[j], &array[j + 1]); */
		/*		print_array(array, size); */
		/*	} */
		/* } */

		for (j = size - 1; j >= 1; j--)
		{
			if (array[j - 1] > array[j])
			{
				swap_ints(&array[j], &array[j - 1]);
				print_array(array, size);
			}
		}
	}
}
