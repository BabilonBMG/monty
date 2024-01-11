#include "monty.h"

/**
 * f_push - Function that adds an element to a stack
 * @stack: The pointer to address of head node of a stack
 * @line_number: working line number of a Monty Bytecode file
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	int x;
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	} for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	} new->n = atoi(op_toks[1]);
	if (check_mode(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	} else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
			new->prev = tmp;
			new->next = NULL;
			tmp->next = new;
	}
}
/**
 * f_pall - Function that prints all members of a stack
 * @stack: The pointer to address of head node of a stack
 * @line_number: Current working line number of Monty Bytecodes file
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}
