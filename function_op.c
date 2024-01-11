#include "monty.h"

/**
 * f_push - Function that adds an element to a stack
 * @head: The pointer to address of head node of a stack
 * @number: Number of nodes to be added to the list 
 */

void f_push(stack_t **head, unsigned int number)
{
	stack_t *node;
	(void)number;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(load.buf);
		fclose(load.file);
		exit(EXIT_FAILURE);
	}
	node->prev = NULL;
	node->n = load.data;
	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
	}
	else
	{
		(*head)->prev = node;
		node->next = *head;
		*head = node;
	}
}

/**
 * f_pall - Function that prints all members of a stack
 * @head: The pointer to address of head node of a stack
 * @number: number of nodes to be added to the list 
 */

void f_pall(stack_t **head, unsigned int number)
{
	stack_t *node = *head;
	(void)number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
