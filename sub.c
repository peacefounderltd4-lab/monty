#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	top->next->n -= top->n;

	*stack = top->next;
	(*stack)->prev = NULL;

	free(top);
}
