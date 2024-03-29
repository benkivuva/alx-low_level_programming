#include "lists.h"

/**
 * add_nodeint - function that adds a new node at the beginning of a list.
 * @head: A pointer to the head of the list
 * @n: The integer added to the new node.
 *
 * Return: Pointer to the new node, NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	/* Create a new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	/*  Set the new node values */
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
