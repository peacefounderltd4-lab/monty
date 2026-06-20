#include "monty.h"

void pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;
	(void)line;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
