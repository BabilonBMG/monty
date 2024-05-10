#include "monty.h"

/**
 * pall - function that prints all the values on the stack starting
 * from top of the stack
 * @line_number: Number of commands
 * @stack:linked list representation of a stack
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
