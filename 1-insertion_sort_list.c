#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: pointer to head of list
 * Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next, *last_curr;

	if (list == NULL || *list == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		last_curr = curr;
		while (curr->prev && curr->prev->n > curr->n)
		{
			prev = curr->prev;
			next = curr->next;
			curr->prev = prev->prev;
			curr->next = prev;
			prev->prev = curr;
			prev->next = next;
			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;
			if (prev->next != NULL)
				prev->next->prev = prev;
			print_list((const listint_t *) *list);
		}
		curr = last_curr;
		curr = curr->next;
	}
}
