#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list
 * @h: Pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *temp, *prev = NULL;

	while (*h != NULL)
	{
		size++;
		temp = *h;
		*h = (*h)->next;
		if (temp < prev)
		{
			free(temp);
			break;
		}
		free(temp);
		prev = temp;
	}
	*h = NULL;
	return (size);
}
