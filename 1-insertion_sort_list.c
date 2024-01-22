#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_list(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * insertion_sort_list - insetion sort function
 *
 * @list: list of items
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	int count = 0;
	int i, key, j;
	listint_t *data = *list;
	int *array;
	
	while (data != NULL)
	{
		count++;
		data = data->next;
	}
	array = (int *)malloc(count * sizeof(int));
	data = *list;
	for (i = 0; i < count; i++)
	{
		array[i] = data->n;
		data = data->next;
	}
	for (i = 1; i < count; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		data = create_list(array, count);
		*list = data;
		print_list(*list);
	}
	free(array);
}
