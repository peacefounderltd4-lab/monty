#include "monty.h"

/**
 * stack_mode - sets the stack mode
 * @stack: pointer to the stack
 * @line_number: line number
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_mode_flag = 0;
}

/* Global variable used to select stack or queue mode */
int stack_mode_flag = 0;
