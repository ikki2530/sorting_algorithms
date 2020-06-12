#include "sort.h"

/**
 *insertion_sort_list - sort an doubly linked list, insertion method.
 *@list:Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sort, *prog;
	int flag = 0;

	if (*list == NULL || list == NULL)
		return;
	prog = (*list)->next;
	while (prog)
	{
		sort = prog->prev;
		temp = prog->next;
		if (temp == NULL)
			flag = 1;
		if (sort->n > prog->n)
		{
			while (sort)
			{
				if (sort->n > prog->n)
			}
		}
	}