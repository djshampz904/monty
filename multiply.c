#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @head: stack head
 * @counter: line_number
 * return: no return
*/

void multiply(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int stackSize = 0, result;

	h = *head;
	while (h)
	{
		h = h->next;
		stackSize++;
	}

	if (stackSize < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	result = h->next->n * h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
