#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 *
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	const listint_t *temp;
	size_t tally;

	tally = 0;
	current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		tally++;
		temp = current;
		current = current->next;
		if (temp <= current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			exit(98);
		}
	}
	return (tally);
}
