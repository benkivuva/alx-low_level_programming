#include "lists.h"

/**
 * add_nodeint_end - Add node at the end of the linked list.
 * @head: Pointer to the head of the list.
 * @n: The integer to be added to the new list.
 *
 * Return: Pointer to the new node, NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *current;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}

	return (new_node);
}
