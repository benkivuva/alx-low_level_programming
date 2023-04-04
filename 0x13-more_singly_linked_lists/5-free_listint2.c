#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: Pointer to the head of the list.
 *
 * This function frees all the nodes of a linked list starting from the head.
 * It also sets the head pointer to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	*head = NULL;
}
