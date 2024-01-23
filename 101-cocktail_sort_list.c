#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swaping = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swaping != 0)
	{
		swaping = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap(list, temp);
				swaping = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swaping == 0)
			break;
		swaping = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap(list, temp->prev);
				swaping = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
