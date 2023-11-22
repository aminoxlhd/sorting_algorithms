#include "sort.h"

/**
 * exchange_nodes - Exchange two nodes in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @node_a: Pointer to the first node.
 * @node_b: Pointer to the second node.
 */
void exchange_nodes(listint_t **head, listint_t *nodeA, listint_t *nodeB)
{
	if (nodeA->prev)
		nodeA->prev->next = nodeB;
	else
		*head = nodeB;

	if (nodeB->next)
		nodeB->next->prev = nodeA;

	nodeA->next = nodeB->next;
	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;
}
/*
* cocktail_sort_list - a function that sorts a doubly linked list of integers
* in ascending order using the Cocktail shaker sort algorithm
* @list: the list we want to sort.
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *nodeA, *nodeB, *end;

	int toContinue = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	end = NULL;
	while (toContinue)
	{
		nodeA = *list;
		while (nodeA->next != end)
		{
			nodeB = nodeA->next;
			if (nodeA->n > nodeB->n)
			{
				toContinue = 1;
				exchange_nodes(list, nodeA, nodeB);
				print_list(*list);
			}
			else
			{
				nodeA = nodeA->next;
			}
		}
		end = nodeA;
		nodeA = nodeA->prev;
		while (nodeA != NULL && nodeA->prev != end)
		{
			nodeB = nodeA->prev;
			if (nodeA->n < nodeB->n)
			{
				toContinue = 1;
				exchange_nodes(list, nodeB, nodeA);
				print_list(*list);
			}
			else
			{
				nodeA = nodeA->prev;
			}
		}
	}
}
