#include "monty.h"

/**
 * execute_file - executes a Monty file
 * @file: file containing instructions
 *
 * Return: nothing
 */
void execute_file(FILE *file)
{
	char *line;
	char *opcode;
	size_t buffer_size;
	ssize_t read;
	unsigned int line_number;
	stack_t *stack;
	void (*func)(stack_t **, unsigned int);

	line = NULL;
	buffer_size = 0;
	line_number = 0;
	stack = NULL;

	while ((read = getline(&line, &buffer_size, file)) != -1)
	{
		line_number++;

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Ignore empty lines and comments */
		opcode = line;

		while (*opcode == ' ' || *opcode == '\t')
			opcode++;

		if (*opcode == '\0' || *opcode == '#')
			continue;

		opcode = strtok(opcode, " \t");

		if (opcode == NULL)
			continue;

		func = get_op_func(opcode);

		if (func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
			free(line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}

		func(&stack, line_number);
	}

	free(line);
	free_stack(stack);
}
