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

		opcode = strtok(line, " \t");

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
 * execute_brainfuck - executes a Brainf*ck program
 * @file: file containing Brainf*ck instructions
 *
 * Return: nothing
 */
void execute_brainfuck(FILE *file)
{
	char *program;
	size_t size;
	size_t len;
	size_t i;
	size_t ptr;
	unsigned char *memory;
	int loop;

	program = NULL;
	size = 0;
	len = 0;
	ptr = 0;

	while (getline(&program, &size, file) != -1)
	{
		len += strlen(program);
	}

	free(program);
	rewind(file);

	program = malloc(len + 1);
	if (program == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (fread(program, 1, len, file) != len)
	{
		free(program);
		fprintf(stderr, "Error: can't read file\n");
		exit(EXIT_FAILURE);
	}

	program[len] = '\0';

	memory = calloc(30000, sizeof(unsigned char));
	if (memory == NULL)
	{
		free(program);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	i = 0;

	while (i < len)
	{
		switch (program[i])
		{
		case '>':
			ptr++;
			break;

		case '<':
			if (ptr > 0)
				ptr--;
			break;

		case '+':
			memory[ptr]++;
			break;

		case '-':
			memory[ptr]--;
			break;

		case '.':
			putchar(memory[ptr]);
			break;

		case ',':
			memory[ptr] = getchar();
			break;

		case '[':
			if (memory[ptr] == 0)
			{
				loop = 1;
				while (loop && ++i < len)
				{
					if (program[i] == '[')
						loop++;
					else if (program[i] == ']')
						loop--;
				}
			}
			break;

		case ']':
			if (memory[ptr] != 0)
			{
				loop = 1;
				while (loop && i > 0)
				{
					i--;
					if (program[i] == ']')
						loop++;
					else if (program[i] == '[')
						loop--;
				}
			}
			break;

		default:
			break;
		}

		i++;
	}

	free(memory);
	free(program);
}
