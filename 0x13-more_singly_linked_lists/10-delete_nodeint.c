#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index of the linked list
 * @head: A pointer to a pointer to the first node of the listint_t list
 * @index: The index of the node to delete
 *
 * Return: 1 if succeeded, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous, *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}

	previous = *head;
	current = previous->next;
	for (i = 1; current != NULL && i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	if (i != index || current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}
