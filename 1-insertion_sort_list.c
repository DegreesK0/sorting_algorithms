#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - insetion sort function
 *
 * @list: list of items
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *data = *list;
	while (data != NULL)
	{
		listint_t *next = data->next;
		data->next = NULL;
		data->prev = NULL;
		if (sorted == NULL || sorted->n >= data->n)
		{
			data->next = sorted;
			if (sorted != NULL)
			{
				sorted->prev = data;
			}
			sorted = data;
		}
		else
		{
			listint_t *current = sorted;
			while (current->next != NULL && current->next->n < data->n)
			{
				current = current->next;
			}
			data->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = data;
			}
			data->prev = current;
			current->next = data;
		}
		data = next;
	}
	print_list(sorted);
	*list = sorted;
}
