#include "sort.h"

/**
 * swap - swaps A and B nodes in list
 * @head: head node of list
 * @node_a: node A
 * @node_b: node B
 */
void swap(listint_t **head, listint_t *node_a, listint_t *node_b)
{
	listint_t *last, *next;

	last = node_a->prev;
	next = node_b->next;

	if (last)
		last->next = node_b;
	else
		*head = node_b;
	node_a->prev = node_b;
	node_a->next = next;
	node_b->prev = last;
	node_b->next = node_a;

	if (next)
		next->prev = node_a;
}

/**
 * insert_sort_list - uses the insert sort algorithm
 * @list: list to be sorted
 */
void insert_sort_list(listint_t **list)
{
	listint_t *temp, *forward;

	if (!list || !*list || !(*list)->next)
		return;

	for (forward = (*list)->next; forward && forward->prev;
			forward = forward->next)
	{
		for (; forward && forward->prev && forward->n < forward->prev->n;
				forward = forward->prev)
		{
			temp = forward->prev;
			swap(list, temp, forward);
			print_list(*list);
			forward = forward->prev;
		}

	}
}
