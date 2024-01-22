#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swap two datas.
 * @head: A pointer to the head.
 * @data1: A pointer to the first element to swap.
 * @data2: The second element to swap.
 * Return: void
 */
void swap(listint_t **head, listint_t **data1, listint_t *data2)
{
	(*data1)->next = data2->next;
	if (data2->next != NULL)
		data2->next->prev = *data1;
	data2->prev = (*data1)->prev;
	data2->next = *data1;
	if ((*data1)->prev != NULL)
		(*data1)->prev->next = data2;
	else
		*head = data2;
	(*data1)->prev = data2;
	*data1 = data2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list
 * using the insertion sort algorithm.
 * @list: A pointer to the head.
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *cur, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (cur = (*list)->next; cur != NULL; cur = tmp)
	{
		insert = cur->prev;
		tmp = cur->next;
		while (insert != NULL && cur->n < insert->n)
		{
			swap(list, &insert, cur);
			print_list(*list);
		}
	}
}
