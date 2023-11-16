#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Removes the top element in the stack
 * @stack: the stack pointer
 * @line_number: line number of the executing line
 * Return: void
 */

void pop(my_stack_t **stack, unsigned int line_number)
{
	my_stack_t *temp = (*stack);


	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = temp->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
