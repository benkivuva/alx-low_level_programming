#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a
 *                           listint_t list.
 * @head: A pointer to a pointer to the head node of the list.
 * @idx: The index of the list where the new node should be added. Indexing
 *       starts at 0.
 * @n: The integer data to be stored in the new node.
 *
 * Return: If memory allocation fails or the function fails to add the new
 *         node - NULL. Otherwise - a pointer to the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *prev_node = NULL, *current_node = *head;
	unsigned int node_idx = 0;

	while (current_node && node_idx < idx)
	{
		prev_node = current_node;
		current_node = current_node->next;
		node_idx++;
	}

	if (node_idx < idx)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = current_node;

	if (prev_node)
		prev_node->next = new_node;
	else
		*head = new_node;

	return (new_node);
}
