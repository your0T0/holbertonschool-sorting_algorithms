#include "sort.h"

/**
 * swap_nodes - swaps a node with its previous node in a doubly linked list
 * @list: pointer to the head of the list
 * @node: pointer to the node to move left
 */
static void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;

	if (prev->prev)
		prev->prev->next = node;
	else
		*list = node;

	node->prev = prev->prev;

	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;

	node->next = prev;
	prev->prev = node;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		next = curr->next;

		while (curr->prev && curr->n < curr->prev->n)
		{
			swap_nodes(list, curr);
			print_list(*list);
		}

		curr = next;
	}
}
