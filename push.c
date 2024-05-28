#include "monty.h"

/**
 * push - Function that pushes elements to the stack
 * @line_number: attribute that counts number of instructions
 * @stack: Pointer to doubly linked list representing stack
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int value;
	char *argument;

	argument = strtok(NULL, " \t\n");

	if (argument == NULL)
	{
		fprint(stderr, "L&u: usage: push integer\n", line number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
