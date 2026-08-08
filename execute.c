#include "monty.h"

/**
 * execute_file - executes a Monty bytecode file
 * @file: file containing Monty instructions
 *
 * Return: nothing
 */
void execute_file(FILE *file)
{
	char *line = NULL;
	char *opcode;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		/* Remove newline */
		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		/*
		 * Find first non-space character.
		 * If it is '#', the whole line is a comment.
		 */
		opcode = line;

		while (*opcode == ' ' || *opcode == '\t')
			opcode++;

		if (*opcode == '\0')
			continue;

		if (*opcode == '#')
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
