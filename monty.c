#include "monty.h"

instruction_t ops[] = {
	{"pall", pall},
	{"push", push},
	{"pint", pint},
	{"pop", pop},
};

/**
 * main - This function allows the  program entry point
 * @argv: This attribute receives the argument variable
 * @argc: this attribute takes argument counts
 *
 * Return: always 0 on Success
 */

int main(int argc, char **argv)
{
	stack_t *stack;
	unsigned int line_number = 1;
	int read;

	char *line = NULL;
	size_t len = 0;
	FILE *file;
	int a = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, file)) != -1)
	{
		char *token = strtok(line, " \t\n");

		if (token != NULL)
		{
			for (; a < (int)sizeof(ops) / (int)sizeof(ops[0]); a++)
			{
				if (strcmp(token, ops[a].opcode) == 0)
				{
					ops[a].f(&stack, line_number);
					break;
				}
			}
		}
		line_number++;
	}
	free(line), fclose(file), exit(EXIT_SUCCESS);
	return (0);
}
