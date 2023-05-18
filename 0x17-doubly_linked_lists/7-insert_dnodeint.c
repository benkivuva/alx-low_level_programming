#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the address of the head node.
 * @idx: Index at which to insert the new node.
 * @n: Data to be stored in the new node.
 *
 * Return: Address of the new node, NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *ptr = NULL, *newNode = NULL;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (ptr = *h; idx > 1 && ptr; idx--, ptr = ptr->next)
		;

	if (ptr == NULL)
		return (NULL);

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = ptr->next;
	newNode->prev = ptr;

	if (ptr->next != NULL)
		ptr->next->prev = newNode;

	ptr->next = newNode;

	return (newNode);
}
