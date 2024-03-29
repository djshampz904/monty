#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;

	while (h)
	{
		if (h->n <= 0 || h->n > 127)
			break;
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
