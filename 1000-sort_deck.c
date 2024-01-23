#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * jib_value - gets the relative value of a card from it's string value
 * @str: string value of the card
 *
 * Return: relative value of the card (0 through 12)
 */
int jib_value(const char *str)
{
	int i;
	char *array[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (i = 0; i < 13; i++)
	{
		if (strcmp(str, array[i]) == 0)
		{
			return (i);
		}
	}
	exit(1);
}

/**
 * swap_node - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @node: node to swap
 *
 * Return: void
 */
void swap_node(deck_node_t **list, deck_node_t *node)
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
 * sort_deck - sorts a linked list deck of cards
 * @deck: double pointer to the deck to sort
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	char swaping = 1, M1, M2;
	deck_node_t *dabaa;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	dabaa = *deck;
	while (swaping != 0)
	{
		swaping = 0;
		while (dabaa->next != NULL)
		{
			M1 = jib_value(dabaa->card->value) + 13 * dabaa->card->kind;
			M2 = jib_value(dabaa->next->card->value) + 13 * dabaa->next->card->kind;
			if (M1 > M2)
			{
				swap_node(deck, dabaa);
				swaping = 1;
			}
			else
				dabaa = dabaa->next;
		}
		if (swaping == 0)
			break;
		swaping = 0;
		while (dabaa->prev != NULL)
		{
			M1 = jib_value(dabaa->card->value) + 13 * dabaa->card->kind;
			M2 = jib_value(dabaa->prev->card->value) + 13 * dabaa->prev->card->kind;
			if (M1 < M2)
			{
				swap_node(deck, dabaa->prev);
				swaping = 1;
			}
			else
				dabaa = dabaa->prev;
		}
	}
}
