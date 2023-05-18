#include "lists.h"

/**
 * add_dnodeint - Adds  new node to the beginning of  dlistint_t list.
 * @head: Pointer to the head of the  list.
 * @n: Integer for the new node to contain.
 *
 * Return: If  function fails - NULL.
 *         Else - the address of  new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
