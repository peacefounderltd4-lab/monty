#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void)line_number;

	if (!new)
		exit(EXIT_FAILURE);

	new->n = 0;
	new->next = NULL;

	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	if (mode == 0)
	{
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		stack_t *tmp = *stack;

		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new;
		new->prev = tmp;
	}
}
