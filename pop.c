#include "monty.h"

void pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
