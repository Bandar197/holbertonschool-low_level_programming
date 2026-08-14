#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * @h: pointer to the head pointer
 * @idx: index where the node should be inserted
 * @n: value to store in the new node
 *
 * Return: address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
		unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int count = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;

	while (current != NULL && count < idx)
	{
		current = current->next;
		count++;
	}

	if (count != idx)
		return (NULL);

	if (current == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = current->prev;
	new->next = current;
	current->prev->next = new;
	current->prev = new;

	return (new);
}
