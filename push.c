#include "monty.h"

/**
 * push - Function to push a node to the top of stack
 * @stack: Function that points to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int nline)
{
        stack_t *new;

        if (stack == NULL)
        {
                fprintf(stderr, "L%d: stack not found\n", nline);
                exit(EXIT_FAILURE);
        }

        new = malloc(sizeof(stack_t));
        if (new == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                free_stack(stack);
                exit(EXIT_FAILURE);
        }

        new->next = *stack;
        new->prev = NULL;
        new->n = arg.arg;
        if (*stack)
                (*stack)->prev = new;
        *stack = new;
}

/**
 * pall - Function that prints the data of all nodes in stack
 * @stack: Function that points to the head node pointer of stack
 * @nline: the line number
 *
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int nline)
{
        stack_t *temp;
        (void)nline;

        temp = *stack;
        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }
}
