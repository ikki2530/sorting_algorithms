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
 * move_forward - move forward
 * @list2: head of the list
 * Return: Node a the end of the list
*/
listint_t *move_forward(listint_t **list2)
{
	listint_t *temp, *current;

	current = (*list2)->next;
	while (current)
	{
		while (current->prev->n > current->n)
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
				*list2 = current;

			current = current->next;
			print_list(*list2);

		}
		if (current->next == NULL)
			break;
		current = current->next;
	}
	/*printf("last value(inside function) %d\n", current->n);*/
	return (current);
}

/**
 * cocktail_sort_list - sorts a linked list using cocktail sort list
 * @list: list to be sorted
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *rev, *temp2;
	int flag = 1;

	if (list == NULL || *list == NULL || dlistint_len(*list) == 1)
		return;
	while (1)
	{
		temp = move_forward(&(*list));
		/*if (temp == NULL) return;*/
		rev = temp->prev;
		flag = 1;
		while (rev)
		{
			while (rev->next->n < rev->n)
			{
				/*printf("inside the while\n");*/
				temp2 = rev->next;
				rev->next = temp2->next; /*step 1*/
				if (rev->prev != NULL) /*step 2*/
					rev->prev->next = temp2;
				temp2->prev = rev->prev; /*step 3*/
				rev->prev = temp2; /*step 4*/
				if (temp2->next != NULL) /*step 5*/
					temp2->next->prev = rev;
				temp2->next = rev; /*step 6*/
				rev = rev->prev;
				if (rev->prev == NULL)
					*list = rev;
				flag = 0;
				print_list(*list);
			}
			if (rev->prev == NULL)
				break;
			rev = rev->prev;
		}
		if (flag == 1)
			return;
	}
}
