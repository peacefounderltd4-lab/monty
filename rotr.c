#include "monty.h"

void rotr(stack_t **stack, unsigned int line)
{
	stack_t *last;

	(void)line;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
