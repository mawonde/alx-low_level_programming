#include "lists.h"

/**
 * add_dnodeint_end - Adds  new node at  end of the  list.
 * @head: Pointer to the head of the dlistint_t list.
 * @n: Integer for the new node to contain.
 *
 * Return: If  fails - NULL.
 *         Else - the address of the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *last;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;

	return (new);
}
