#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - function that  swaps  the  nodes in
 * a doubly linked list
 * @list: doubly linked list
 * @node1: node one
 * @node2: node two
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;

	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	node1->prev = node2;
	node2->next = node1;

	print_list(*list);
}

/**
 * insert - function htat  insert node in its
 * ordered position in a doubly linked list
 * @list: list of nodes
 * @node1: node being inserted
 * @node2: node to insert infront of
 */

void insert(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node2 == *list)
	{
		node1->prev->next = node1->next;

		if (node1->next)
			node1->next->prev = node1->prev;

		node1->next = *list;
		node1->prev = NULL;
		(*list)->prev = node1;
		*list = node1;
	}
	else
	{
		node1->prev->next = node1->next;

		if (node1->next)
			node1->next->prev = node1->prev;

		node2->prev->next = node1;
		node1->prev = node2->prev;
		node1->next = node2;
		node2->prev = node1;
	}

	print_list(*list);
}

/**
 * insertion_sort_list - function that sorts a doubly-linked
 * list using the insertion sort method
 * algorithm
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *curr, *node;

	if (list && *list)
	{
		current = *list;

		while (current)
		{
			curr = current;
			node = current;

			while (curr->prev && (node->n < curr->prev->n))
				swap(list, curr->prev, node);
			current = current->next;
		}
	}
}
