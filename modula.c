#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int stackSize = 0, results;

	h = *head;
	while (h)
	{
		h = h->next;
		stackSize++;
	}

	if (stackSize < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
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

	results = h->next->n % h->n;
	h->next->n = results;
	*head = h->next;
	free(h);
}
