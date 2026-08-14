#include "lists.h"

/**
 * sum_dlistint - calculates the sum of all data in a list
 * @head: pointer to the head of the list
 *
 * Return: sum of all values
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
