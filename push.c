#include "monty.h"

/**
 * is_integer - checks if a string represents an integer
 * @str: string to check
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	if (str[i] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * push - pushes an integer onto the stack
 * @stack: pointer to the stack
 * @line_number: line number of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *argument;

	argument = strtok(NULL, " \t\n");
	if (!is_integer(argument))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
