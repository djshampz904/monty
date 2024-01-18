#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void rotl(stack_t **head, __attribute((unused)) unsigned int counter)
{
	stack_t *h = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
		return;

	temp = (*head)->next;
	temp->prev = NULL;

	while (h->next != NULL)
		h = h->next;

	h->next = *head;
	(*head)->next = NULL;
	(*head)->prev = h;
	(*head) = temp;

}
