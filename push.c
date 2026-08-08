#include "monty.h"

/**
 * is_integer - checks if a string is an integer
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
 * push - pushes a new node
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *current;
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
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	/*
	 * STACK mode = LIFO
	 * New element becomes the top.
	 */
	if (stack_mode_flag == 0)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		/*
		 * QUEUE mode = FIFO
		 * New element goes to the end.
		 */
		current = *stack;

		while (current->next != NULL)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
}
