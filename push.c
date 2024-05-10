#include "monty.h"

/**
 * push - Function that pushes elements to the stack
 * @line_number: number of instructions
 * @stack: Pointer to doubly linked list representing stack
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node = NULL;
	char *argument;

	/* Use this line to extract the push argument */
	argument = strtok(NULL, " \t\n");

	/* Analyze if argument exists */
	if (argument == NULL)
	{
		fprint(stderr, "L&u: usage: push integer\n", line number);
		exit(EXIT_FAILURE);
	}

	/* Func that converts arg to an int using atoi */
	value = atoi(argument);

	/* Creates a new stack node */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initializes the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* Func adds the new node to the stack */
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}


