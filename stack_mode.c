#include "monty.h"

int stack_mode_flag = 0;

void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	stack_mode_flag = 0;
}
