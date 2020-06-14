#include "sort.h"

/**
 * dlistint_len - length of a doubly linked list dlistin_t
 * @h: head of the doubly linked list
 * Return: number of elements of the doubly linked list
 */
size_t dlistint_len(const listint_t *h)
{
	const listint_t *current = h;
	int lg = 0;

	if (h == NULL)
		return (lg);
	while (current)
	{
		lg++;
		current = current->next;
	}
	return (lg);
}
/**
 *insertion_sort_list - sort an doubly linked list, insertion method.
 *@list:Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;
	int lg;

	lg = dlistint_len(*list);
	if (*list == NULL || list == NULL || lg < 2)
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
