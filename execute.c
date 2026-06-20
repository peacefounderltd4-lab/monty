#include "monty.h"

void execute(char *line, stack_t **stack, unsigned int line)
{
	int i;
	char *opcode;
	instruction_t ops[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr}, {"stack", _stack},
		{"queue", _queue}, {NULL, NULL}
	};

	opcode = strtok(line, " \n\t");
	if (!opcode || opcode[0] == '#')
		return;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}
