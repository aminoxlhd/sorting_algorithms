#include "sort.h"

/**
 * exchange_nodes - Exchange two nodes in a doubly linked list
 * @head: Pointer to the head of the list
 * @nodeA: Pointer to the first node
 * @nodeB: Pointer to the second node
 */
void exchange_nodes(listint_t **head, listint_t **nodeA, listint_t *nodeB)
{
	listint_t *prevA = (*nodeA)->prev;
	listint_t *nextB = nodeB->next;

	(*nodeA)->prev = nodeB;
	nodeB->next = *nodeA;
	(*nodeA)->next = nextB;

	if (nextB != NULL)
		nextB->prev = *nodeA;

	if (prevA != NULL)
		prevA->next = nodeB;

	else
		*head = nodeB;

	nodeB->prev = prevA;
	*nodeA = nodeB->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * using the Insertion sort algorithm
 * @list: Pointer to the head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;

		while (prev != NULL && current->n < prev->n)
		{
			exchange_nodes(list, &prev, current);
			print_list((const listint_t *)*list);
		}
	current = current->next;
	}
}
