#include "sort.h"

/**
 *insertion_sort_list - sort an doubly linked list, insertion method.
 *@list:Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			/*Add condcion current->prev != NULL*/
			temp = current->prev;

			/*step 1*/
			current->prev = temp->prev;
			/*step 2*/
			if (current->next != NULL)
				current->next->prev = temp;
			/*step 3*/
			temp->next = current->next;
			/*step 4*/
			current->next = temp;
			/*step 5*/
			if (temp->prev != NULL)
				temp->prev->next = current;
			/*step 6*/
			temp->prev = current;

			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}

		current = current->next;
	}
}
