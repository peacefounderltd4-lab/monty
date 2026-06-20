#include "monty.h"

void pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;
	(void)line;

	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
