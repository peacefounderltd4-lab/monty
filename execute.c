#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_file - executes Monty bytecode
 * @file: file containing Monty instructions
 *
 * Return: nothing
 */
void execute_file(FILE *file)
{
	char *line = NULL;
	char *opcode;
	size_t buffer_size = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*func)(stack_t **, unsigned int);

	while ((read = getline(&line, &buffer_size, file)) != -1)
	{
		line_number++;

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		opcode = line;

		/* Skip spaces and tabs */
		while (*opcode == ' ' || *opcode == '\t')
			opcode++;

		/* Empty line or comment */
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


/**
 * execute_brainfuck - executes a Brainfuck file
 * @file: Brainfuck file
 *
 * Return: nothing
 */
void execute_brainfuck(FILE *file)
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t read;

	while ((read = getline(&line, &buffer_size, file)) != -1)
	{
		(void)read;
	}

	free(line);
}
