#include "monty.h"

/**
 * div_op - divides the second top element by the top element
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: nothing
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next->n = top->next->n / top->n;
	*stack = top->next;

	free(top);
}
