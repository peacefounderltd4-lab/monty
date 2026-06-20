#include "monty.h"

int mode = 0;

void _stack(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	mode = 0;
}

void _queue(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	mode = 1;
}
