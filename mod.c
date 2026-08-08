#include "monty.h"

/**
 * mod - computes the remainder of the second top by the top
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n %= top->n;

	*stack = top->next;
	(*stack)->prev = NULL;

	free(top);
}
