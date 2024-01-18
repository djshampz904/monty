#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void _div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int stackSize = 0, dividend;

	h = *head;
	while (h)
	{
		h = h->next;
		stackSize++;
	}

	if (stackSize < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	dividend = h->next->n / h->n;
	h->next->n = dividend;
	*head = h->next;
	free(h);
}
