#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head of the listint_t list.
 * @index: The index of the node starting at 0.
 *
 * Return: If the node does not exist - NULL.
 *         Otherwise - A pointer to the nth node.
 **/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int tally = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		if (tally == index)
			return (current);

		tally++;
		current = current->next;
	}

	return (NULL);
}
