#include "monty.h"


/**
 * main - This function allows opens program entry point
 * @argv: This attribute receives the argument variable
 * @argc: this attribute takes argument counts
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parsefile(file);
	return (EXIT_SUCCESS);
}
