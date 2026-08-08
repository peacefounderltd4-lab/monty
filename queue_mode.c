#include "monty.h"

/**
 * queue_mode - sets the queue mode
 * @stack: pointer to the stack
 * @line_number: line number
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_mode_flag = 1;
}
