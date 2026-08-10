#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *extension;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	extension = strrchr(argv[1], '.');

	if (extension != NULL && strcmp(extension, ".bf") == 0)
		execute_brainfuck(file);
	else
		execute_file(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
